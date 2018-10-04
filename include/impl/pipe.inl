/*
 * Copyright 2018 Justas Masiulis
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "../io/pipe.hpp"

namespace ntw::io {

    template<class Handle>
    NT_FN pipe_traits<Handle>::open(void*&              handle,
                                    OBJECT_ATTRIBUTES&  attributes,
                                    const options_type& options,
                                    unsigned long       disposition)
    {
        IO_STATUS_BLOCK iosb;
        auto            timeout = make_large_int(options._timeout);
        return LI_NT(NtCreateNamedPipeFile)(&temp_handle,
                                            options._access | SYNCHRONIZE,
                                            &attributes,
                                            &iosb,
                                            options._share_access,
                                            disposition,
                                            options._create_options | FILE_SYNCHRONOUS_IO_NONALERT,
                                            options._type,
                                            options._type & 1,
                                            FILE_PIPE_QUEUE_OPERATION,
                                            options._instances_limit,
                                            options._inbound_qouta,
                                            options._outbound_qouta,
                                            &timeout);
    }


    template<class Handle>
    NT_FN basic_pipe<Handle>::_fs_ctl(unsigned long code) const
    {
        IO_STATUS_BLOCK iosb;
        return LI_NT(NtFsControlFile)(handle().get(),
                                      nullptr,
                                      nullptr,
                                      nullptr,
                                      &iosb,
                                      code,
                                      nullptr,
                                      nullptr,
                                      nullptr,
                                      nullptr);
    }

    template<class Handle>
    NT_FN basic_pipe<Handle>::listen()
    {
        return _fs_ctl(FSCTL_PIPE_LISTEN);
    }

    template<class Handle>
    NT_FN basic_pipe<Handle>::disconnect() const
    {
        return _fs_ctl(FSCTL_PIPE_DISCONNECT);
    }

} // namespace ntw::io
