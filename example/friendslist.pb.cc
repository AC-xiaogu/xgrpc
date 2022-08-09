// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friendslist.proto

#include "friendslist.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace friends {
PROTOBUF_CONSTEXPR ResultCode::ResultCode(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.errmsg_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.errcode_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ResultCodeDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResultCodeDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResultCodeDefaultTypeInternal() {}
  union {
    ResultCode _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResultCodeDefaultTypeInternal _ResultCode_default_instance_;
PROTOBUF_CONSTEXPR GetFriendsListRequest::GetFriendsListRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.userid_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct GetFriendsListRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GetFriendsListRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GetFriendsListRequestDefaultTypeInternal() {}
  union {
    GetFriendsListRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GetFriendsListRequestDefaultTypeInternal _GetFriendsListRequest_default_instance_;
PROTOBUF_CONSTEXPR GetFriendsListResponse::GetFriendsListResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.friends_)*/{}
  , /*decltype(_impl_.result_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct GetFriendsListResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GetFriendsListResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GetFriendsListResponseDefaultTypeInternal() {}
  union {
    GetFriendsListResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GetFriendsListResponseDefaultTypeInternal _GetFriendsListResponse_default_instance_;
}  // namespace friends
static ::_pb::Metadata file_level_metadata_friendslist_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_friendslist_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_friendslist_2eproto[1];

const uint32_t TableStruct_friendslist_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::friends::ResultCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::friends::ResultCode, _impl_.errcode_),
  PROTOBUF_FIELD_OFFSET(::friends::ResultCode, _impl_.errmsg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::friends::GetFriendsListRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::friends::GetFriendsListRequest, _impl_.userid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::friends::GetFriendsListResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::friends::GetFriendsListResponse, _impl_.result_),
  PROTOBUF_FIELD_OFFSET(::friends::GetFriendsListResponse, _impl_.friends_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::friends::ResultCode)},
  { 8, -1, -1, sizeof(::friends::GetFriendsListRequest)},
  { 15, -1, -1, sizeof(::friends::GetFriendsListResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::friends::_ResultCode_default_instance_._instance,
  &::friends::_GetFriendsListRequest_default_instance_._instance,
  &::friends::_GetFriendsListResponse_default_instance_._instance,
};

const char descriptor_table_protodef_friendslist_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021friendslist.proto\022\007friends\"-\n\nResultCo"
  "de\022\017\n\007errcode\030\001 \001(\005\022\016\n\006errmsg\030\002 \001(\014\"\'\n\025G"
  "etFriendsListRequest\022\016\n\006userid\030\001 \001(\r\"N\n\026"
  "GetFriendsListResponse\022#\n\006result\030\001 \001(\0132\023"
  ".friends.ResultCode\022\017\n\007friends\030\002 \003(\0142e\n\020"
  "FriendServiceRpc\022Q\n\016GetFriendsList\022\036.fri"
  "ends.GetFriendsListRequest\032\037.friends.Get"
  "FriendsListResponseB\003\200\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_friendslist_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_friendslist_2eproto = {
    false, false, 312, descriptor_table_protodef_friendslist_2eproto,
    "friendslist.proto",
    &descriptor_table_friendslist_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_friendslist_2eproto::offsets,
    file_level_metadata_friendslist_2eproto, file_level_enum_descriptors_friendslist_2eproto,
    file_level_service_descriptors_friendslist_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_friendslist_2eproto_getter() {
  return &descriptor_table_friendslist_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_friendslist_2eproto(&descriptor_table_friendslist_2eproto);
namespace friends {

// ===================================================================

class ResultCode::_Internal {
 public:
};

ResultCode::ResultCode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:friends.ResultCode)
}
ResultCode::ResultCode(const ResultCode& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ResultCode* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.errmsg_){}
    , decltype(_impl_.errcode_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.errmsg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.errmsg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_errmsg().empty()) {
    _this->_impl_.errmsg_.Set(from._internal_errmsg(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.errcode_ = from._impl_.errcode_;
  // @@protoc_insertion_point(copy_constructor:friends.ResultCode)
}

inline void ResultCode::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.errmsg_){}
    , decltype(_impl_.errcode_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.errmsg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.errmsg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ResultCode::~ResultCode() {
  // @@protoc_insertion_point(destructor:friends.ResultCode)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ResultCode::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.errmsg_.Destroy();
}

void ResultCode::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ResultCode::Clear() {
// @@protoc_insertion_point(message_clear_start:friends.ResultCode)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.errmsg_.ClearToEmpty();
  _impl_.errcode_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ResultCode::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 errcode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.errcode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_errmsg();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ResultCode::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:friends.ResultCode)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 errcode = 1;
  if (this->_internal_errcode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_errcode(), target);
  }

  // bytes errmsg = 2;
  if (!this->_internal_errmsg().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_errmsg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:friends.ResultCode)
  return target;
}

size_t ResultCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:friends.ResultCode)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes errmsg = 2;
  if (!this->_internal_errmsg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_errmsg());
  }

  // int32 errcode = 1;
  if (this->_internal_errcode() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_errcode());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResultCode::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ResultCode::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ResultCode::GetClassData() const { return &_class_data_; }


void ResultCode::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ResultCode*>(&to_msg);
  auto& from = static_cast<const ResultCode&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:friends.ResultCode)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_errmsg().empty()) {
    _this->_internal_set_errmsg(from._internal_errmsg());
  }
  if (from._internal_errcode() != 0) {
    _this->_internal_set_errcode(from._internal_errcode());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ResultCode::CopyFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:friends.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResultCode::IsInitialized() const {
  return true;
}

void ResultCode::InternalSwap(ResultCode* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.errmsg_, lhs_arena,
      &other->_impl_.errmsg_, rhs_arena
  );
  swap(_impl_.errcode_, other->_impl_.errcode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ResultCode::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_friendslist_2eproto_getter, &descriptor_table_friendslist_2eproto_once,
      file_level_metadata_friendslist_2eproto[0]);
}

// ===================================================================

class GetFriendsListRequest::_Internal {
 public:
};

GetFriendsListRequest::GetFriendsListRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:friends.GetFriendsListRequest)
}
GetFriendsListRequest::GetFriendsListRequest(const GetFriendsListRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  GetFriendsListRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.userid_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.userid_ = from._impl_.userid_;
  // @@protoc_insertion_point(copy_constructor:friends.GetFriendsListRequest)
}

inline void GetFriendsListRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.userid_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

GetFriendsListRequest::~GetFriendsListRequest() {
  // @@protoc_insertion_point(destructor:friends.GetFriendsListRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GetFriendsListRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void GetFriendsListRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void GetFriendsListRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:friends.GetFriendsListRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.userid_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetFriendsListRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 userid = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.userid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GetFriendsListRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:friends.GetFriendsListRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 userid = 1;
  if (this->_internal_userid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_userid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:friends.GetFriendsListRequest)
  return target;
}

size_t GetFriendsListRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:friends.GetFriendsListRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 userid = 1;
  if (this->_internal_userid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_userid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GetFriendsListRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    GetFriendsListRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetFriendsListRequest::GetClassData() const { return &_class_data_; }


void GetFriendsListRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<GetFriendsListRequest*>(&to_msg);
  auto& from = static_cast<const GetFriendsListRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:friends.GetFriendsListRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_userid() != 0) {
    _this->_internal_set_userid(from._internal_userid());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GetFriendsListRequest::CopyFrom(const GetFriendsListRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:friends.GetFriendsListRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendsListRequest::IsInitialized() const {
  return true;
}

void GetFriendsListRequest::InternalSwap(GetFriendsListRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.userid_, other->_impl_.userid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetFriendsListRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_friendslist_2eproto_getter, &descriptor_table_friendslist_2eproto_once,
      file_level_metadata_friendslist_2eproto[1]);
}

// ===================================================================

class GetFriendsListResponse::_Internal {
 public:
  static const ::friends::ResultCode& result(const GetFriendsListResponse* msg);
};

const ::friends::ResultCode&
GetFriendsListResponse::_Internal::result(const GetFriendsListResponse* msg) {
  return *msg->_impl_.result_;
}
GetFriendsListResponse::GetFriendsListResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:friends.GetFriendsListResponse)
}
GetFriendsListResponse::GetFriendsListResponse(const GetFriendsListResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  GetFriendsListResponse* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.friends_){from._impl_.friends_}
    , decltype(_impl_.result_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_result()) {
    _this->_impl_.result_ = new ::friends::ResultCode(*from._impl_.result_);
  }
  // @@protoc_insertion_point(copy_constructor:friends.GetFriendsListResponse)
}

inline void GetFriendsListResponse::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.friends_){arena}
    , decltype(_impl_.result_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

GetFriendsListResponse::~GetFriendsListResponse() {
  // @@protoc_insertion_point(destructor:friends.GetFriendsListResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GetFriendsListResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.friends_.~RepeatedPtrField();
  if (this != internal_default_instance()) delete _impl_.result_;
}

void GetFriendsListResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void GetFriendsListResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:friends.GetFriendsListResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.friends_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.result_ != nullptr) {
    delete _impl_.result_;
  }
  _impl_.result_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetFriendsListResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .friends.ResultCode result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_result(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bytes friends = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_friends();
            ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GetFriendsListResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:friends.GetFriendsListResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .friends.ResultCode result = 1;
  if (this->_internal_has_result()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::result(this),
        _Internal::result(this).GetCachedSize(), target, stream);
  }

  // repeated bytes friends = 2;
  for (int i = 0, n = this->_internal_friends_size(); i < n; i++) {
    const auto& s = this->_internal_friends(i);
    target = stream->WriteBytes(2, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:friends.GetFriendsListResponse)
  return target;
}

size_t GetFriendsListResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:friends.GetFriendsListResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bytes friends = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_impl_.friends_.size());
  for (int i = 0, n = _impl_.friends_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      _impl_.friends_.Get(i));
  }

  // .friends.ResultCode result = 1;
  if (this->_internal_has_result()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.result_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GetFriendsListResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    GetFriendsListResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetFriendsListResponse::GetClassData() const { return &_class_data_; }


void GetFriendsListResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<GetFriendsListResponse*>(&to_msg);
  auto& from = static_cast<const GetFriendsListResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:friends.GetFriendsListResponse)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.friends_.MergeFrom(from._impl_.friends_);
  if (from._internal_has_result()) {
    _this->_internal_mutable_result()->::friends::ResultCode::MergeFrom(
        from._internal_result());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GetFriendsListResponse::CopyFrom(const GetFriendsListResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:friends.GetFriendsListResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendsListResponse::IsInitialized() const {
  return true;
}

void GetFriendsListResponse::InternalSwap(GetFriendsListResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.friends_.InternalSwap(&other->_impl_.friends_);
  swap(_impl_.result_, other->_impl_.result_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetFriendsListResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_friendslist_2eproto_getter, &descriptor_table_friendslist_2eproto_once,
      file_level_metadata_friendslist_2eproto[2]);
}

// ===================================================================

FriendServiceRpc::~FriendServiceRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* FriendServiceRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_friendslist_2eproto);
  return file_level_service_descriptors_friendslist_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* FriendServiceRpc::GetDescriptor() {
  return descriptor();
}

void FriendServiceRpc::GetFriendsList(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::friends::GetFriendsListRequest*,
                         ::friends::GetFriendsListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetFriendsList() not implemented.");
  done->Run();
}

void FriendServiceRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_friendslist_2eproto[0]);
  switch(method->index()) {
    case 0:
      GetFriendsList(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::friends::GetFriendsListRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::friends::GetFriendsListResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& FriendServiceRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::friends::GetFriendsListRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& FriendServiceRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::friends::GetFriendsListResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

FriendServiceRpc_Stub::FriendServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
FriendServiceRpc_Stub::FriendServiceRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
FriendServiceRpc_Stub::~FriendServiceRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void FriendServiceRpc_Stub::GetFriendsList(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::friends::GetFriendsListRequest* request,
                              ::friends::GetFriendsListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace friends
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::friends::ResultCode*
Arena::CreateMaybeMessage< ::friends::ResultCode >(Arena* arena) {
  return Arena::CreateMessageInternal< ::friends::ResultCode >(arena);
}
template<> PROTOBUF_NOINLINE ::friends::GetFriendsListRequest*
Arena::CreateMaybeMessage< ::friends::GetFriendsListRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::friends::GetFriendsListRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::friends::GetFriendsListResponse*
Arena::CreateMaybeMessage< ::friends::GetFriendsListResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::friends::GetFriendsListResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>