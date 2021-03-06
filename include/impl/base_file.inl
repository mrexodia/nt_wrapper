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
#include "../object/base_file.hpp"

#define NTW_BUILDER_OPTION(builder, function_name, member, value, op) \
    NTW_INLINE constexpr builder& builder::function_name()            \
    {                                                                 \
        member op value;                                              \
        return *this;                                                 \
    }

#define NTW_FILE_OPTION(name, member, value, op) \
    template<class Base>                         \
    NTW_BUILDER_OPTION(file_options_builder<Base>, name, member, value, op)

#define NTW_FILE_ATTRIBUTE_OPTION(name, member, value, op) \
    NTW_BUILDER_OPTION(file_attributes_builder, name, member, value, op)

#define NTW_PIPE_OPTION(name, member, value, op) \
    NTW_BUILDER_OPTION(pipe_options_builder, name, member, value, op)

namespace ntw::obj::detail {

    NTW_FILE_OPTION(reset_share_access, _share_access, 0, =)
    NTW_FILE_OPTION(share_read, _share_access, FILE_SHARE_READ, |=)
    NTW_FILE_OPTION(share_write, _share_access, FILE_SHARE_WRITE, |=)
    NTW_FILE_OPTION(share_delete, _share_access, FILE_SHARE_DELETE, |=)

    NTW_FILE_OPTION(reset_disposition, _disposition, 0, =)
    NTW_FILE_OPTION(open, _disposition, FILE_OPEN, =)
    NTW_FILE_OPTION(create, _disposition, FILE_CREATE, =)
    NTW_FILE_OPTION(supersede, _disposition, FILE_SUPERSEDE, =)
    NTW_FILE_OPTION(overwrite, _disposition, FILE_OVERWRITE, =)
    NTW_FILE_OPTION(open_or_create, _disposition, FILE_OPEN_IF, =)
    NTW_FILE_OPTION(overwrite_or_create, _disposition, FILE_OVERWRITE_IF, =)

    NTW_FILE_OPTION(directory, _options, FILE_DIRECTORY_FILE, |=)
    NTW_FILE_OPTION(non_directory, _options, FILE_NON_DIRECTORY_FILE, |=)
    NTW_FILE_OPTION(write_trough, _options, FILE_WRITE_THROUGH, |=)
    NTW_FILE_OPTION(sequential_access, _options, FILE_SEQUENTIAL_ONLY, |=)
    NTW_FILE_OPTION(random_access, _options, FILE_RANDOM_ACCESS, |=)
    NTW_FILE_OPTION(sync_io_alert, _options, FILE_SYNCHRONOUS_IO_ALERT, |=)
    NTW_FILE_OPTION(sync_io_nonalert, _options, FILE_SYNCHRONOUS_IO_NONALERT, |=)
    NTW_FILE_OPTION(create_tree_connection, _options, FILE_CREATE_TREE_CONNECTION, |=)
    NTW_FILE_OPTION(no_ea_knownledge, _options, FILE_NO_EA_KNOWLEDGE, |=)
    NTW_FILE_OPTION(open_reparse_point, _options, FILE_OPEN_REPARSE_POINT, |=)
    NTW_FILE_OPTION(delete_on_close, _options, FILE_DELETE_ON_CLOSE, |=)
    NTW_FILE_OPTION(open_by_file_id, _options, FILE_OPEN_BY_FILE_ID, |=)
    NTW_FILE_OPTION(open_for_backup, _options, FILE_OPEN_FOR_BACKUP_INTENT, |=)
    NTW_FILE_OPTION(reserve_opfilter, _options, FILE_RESERVE_OPFILTER, |=)
    NTW_FILE_OPTION(requires_oplock, _options, FILE_OPEN_REQUIRING_OPLOCK, |=)
    NTW_FILE_OPTION(complete_if_oplocked, _options, FILE_COMPLETE_IF_OPLOCKED, |=)

    NTW_FILE_OPTION(reset_access, _access, 0, =);

    NTW_FILE_OPTION(full_access, _access, GENERIC_ALL, =);

    NTW_FILE_OPTION(deleteable, _access, DELETE, |=)
    NTW_FILE_OPTION(synchronizable, _access, SYNCHRONIZE, |=)
    NTW_FILE_OPTION(executeable, _access, FILE_EXECUTE, |=)
    NTW_FILE_OPTION(traversible, _access, FILE_TRAVERSE, |=)
    NTW_FILE_OPTION(listable_directory, _access, FILE_LIST_DIRECTORY, |=)

    NTW_FILE_OPTION(generic_readable, _access, FILE_GENERIC_READ, |=)
    NTW_FILE_OPTION(generic_writeable, _access, FILE_GENERIC_WRITE, |=)
    NTW_FILE_OPTION(generic_executeable, _access, FILE_GENERIC_EXECUTE, |=)

    NTW_FILE_OPTION(readable_data, _access, FILE_READ_DATA, |=)
    NTW_FILE_OPTION(readable_attributes, _access, FILE_READ_ATTRIBUTES, |=)
    NTW_FILE_OPTION(readable_extended_attributes, _access, FILE_READ_EA, |=)
    NTW_FILE_OPTION(readable_access_control, READ_CONTROL, |=)

    NTW_FILE_OPTION(writeable_data, _access, FILE_WRITE_DATA, |=)
    NTW_FILE_OPTION(writeable_attributes, _access, FILE_WRITE_ATTRIBUTES, |=)
    NTW_FILE_OPTION(writeable_extended_attributes, _access, FILE_WRITE_EA, |=)
    NTW_FILE_OPTION(writeable_access_control, _access, WRITE_DAC, |=)
    NTW_FILE_OPTION(writeable_ownership, _access, WRITE_OWNER, |=)
    NTW_FILE_OPTION(appendable_data, _access, FILE_APPEND_DATA, |=)

    NTW_FILE_ATTRIBUTE_OPTION(reset_attributes, _attributes, 0, =);
    NTW_FILE_ATTRIBUTE_OPTION(archive, _attributes, FILE_ATTRIBUTE_ARCHIVE, |=)
    NTW_FILE_ATTRIBUTE_OPTION(encrypted, _attributes, FILE_ATTRIBUTE_ENCRYPTED, |=)
    NTW_FILE_ATTRIBUTE_OPTION(hidden, _attributes, FILE_ATTRIBUTE_HIDDEN, |=)
    NTW_FILE_ATTRIBUTE_OPTION(normal, _attributes, FILE_ATTRIBUTE_NORMAL, |=)
    NTW_FILE_ATTRIBUTE_OPTION(offline, _attributes, FILE_ATTRIBUTE_OFFLINE, |=)
    NTW_FILE_ATTRIBUTE_OPTION(readonly, _attributes, FILE_ATTRIBUTE_READONLY, |=)
    NTW_FILE_ATTRIBUTE_OPTION(system, _attributes, FILE_ATTRIBUTE_SYSTEM, |=)
    NTW_FILE_ATTRIBUTE_OPTION(temporary, _attributes, FILE_ATTRIBUTE_TEMPORARY, |=)

    NTW_PIPE_OPTION(async, _completion_mode, FILE_PIPE_COMPLETE_OPERATION, =)
    NTW_PIPE_OPTION(sync, _completion_mode, FILE_PIPE_QUEUE_OPERATION, =)
    NTW_PIPE_OPTION(reset_type, _type, 0, =)
    NTW_PIPE_OPTION(byte_stream, _type, FILE_PIPE_MESSAGE_MODE, &= ~)
    NTW_PIPE_OPTION(message_stream, _type, FILE_PIPE_MESSAGE_TYPE, |=)
    NTW_PIPE_OPTION(accept_remote_clients, _type, FILE_PIPE_ACCEPT_REMOTE_CLIENTS, |=)
    NTW_PIPE_OPTION(reject_remote_clients, _type, FILE_PIPE_REJECT_REMOTE_CLIENTS, |=)

    NTW_INLINE constexpr pipe_options_builder&
    pipe_options_builder::qouta(unsigned long inbound, unsigned long outbound)
    {
        _inbound_qouta  = inbound;
        _outbound_qouta = outbound;
        return *this;
    }

    NTW_INLINE constexpr pipe_options_builder&
    pipe_options_builder::inbound_qouta(unsigned long qouta)
    {
        _inbound_qouta = qouta;
        return *this;
    }

    NTW_INLINE constexpr pipe_options_builder&
    pipe_options_builder::outbound_qouta(unsigned long qouta)
    {
        _outbound_qouta = qouta;
        return *this;
    }


    NTW_INLINE constexpr pipe_options_builder&
    pipe_options_builder::instances_limit(unsigned long limit)
    {
        _instances_limit = limit;
        return *this;
    }

    // default = 5 seconds
    NTW_INLINE constexpr pipe_options_builder&
    pipe_options_builder::timeout(std::int64_t& nanoseconds)
    {
        // the timeout is a negative value
        if(nanoseconds > 0)
            nanoseconds = -nanoseconds;
        _timeout = nanoseconds;
        return *this;
    }


    template<class Derived>
    template<class StringRef>
    NT_FN base_file<Derived>::open(const StringRef& path, const file_options& options) noexcept
    {
        auto            upath      = make_ustr(path);
        auto            attributes = make_attributes(&upath, OBJ_CASE_INSENSITIVE);
        IO_STATUS_BLOCK status_block;

        void*      temp_handle = nullptr;
        const auto status      = LI_NT(NtCreateFile)(&temp_handle,
                                                options._access,
                                                &attributes,
                                                &status_block,
                                                nullptr,
                                                options._attributes,
                                                options._share_access,
                                                options._disposition,
                                                options._create_flags,
                                                nullptr,
                                                0);

        if(NT_SUCCESS(status))
            _handle.reset(temp_handle);

        return status;
    }


    template<class Derived>
    template<class StringRef>
    NT_FN base_file<Derived>::open_as_pipe(const StringRef& path, const pipe_options& options) noexcept
    {
        auto            upath      = make_ustr(path);
        auto            attributes = ntw::make_attributes(&upath, OBJ_CASE_INSENSITIVE);
        IO_STATUS_BLOCK iosb;
        auto            timeout     = make_large_int(options._timeout);
        void*           temp_handle = nullptr;
        // if you want to use MESSAGE bullshit you can't just use the same macros
        const auto status = LI_NT(NtCreateNamedPipeFile)(&temp_handle,
                                                         options._access,
                                                         &attributes,
                                                         &iosb,
                                                         options._share_access,
                                                         options._disposition,
                                                         options._create_options,
                                                         options._type,
                                                         options._type & 1,
                                                         options._completion_mode,
                                                         options._instances_limit,
                                                         options._inbound_qouta,
                                                         options._outbound_qouta,
                                                         &timeout);

        if(NT_SUCCESS(status)) {
            // looking at IDA if iosb.Information == 1 ERROR_ALREADY_EXISTS ?
            if(iosb.Information == 1)
                return STATUS_OBJECT_NAME_EXISTS;
            else
                _handle.reset(temp_handle);
        }

        return status;
    }

    template<class Derived>
    NT_FN base_file<Derived>::size(std::uint64_t& size_out) const noexcept
    {
        IO_STATUS_BLOCK           status_block;
        FILE_STANDARD_INFORMATION info;
        const auto                status = LI_NT(NtQueryInformationFile)(_handle.get(),
                                                          &status_block,
                                                          &info,
                                                          unsigned{ sizeof(info) },
                                                          FileStandardInformation);
        if(NT_SUCCESS(status))
            size_out = static_cast<std::uint64_t>(info.EndOfFile.QuadPart);

        return status;
    }

    template<class Derived>
    template<class StringRef /* wstring_view or UNICODE_STRING */>
    NT_FN base_file<Derived>::destroy(const StringRef& path, bool case_sensitive) noexcept
    {
        auto upath      = make_ustr(path);
        auto attributes = make_attributes(&upath, case_sensitive ? 0 : OBJ_CASE_INSENSITIVE);
        return LI_NT(NtDeleteFile)(&attributes);
    }


} // namespace ntw::obj::detail

#undef NTW_BUILDER_OPTION
#undef NTW_FILE_OPTION
#undef NTW_FILE_ATTRIBUTE_OPTION
#undef NTW_PIPE_OPTION
