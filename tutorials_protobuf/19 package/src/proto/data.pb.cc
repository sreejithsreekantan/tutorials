// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: data.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "data.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protosree {

namespace {

const ::google::protobuf::Descriptor* Data_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Data_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* LifeStage_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_data_2eproto() {
  protobuf_AddDesc_data_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "data.proto");
  GOOGLE_CHECK(file != NULL);
  Data_descriptor_ = file->message_type(0);
  static const int Data_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, s_),
  };
  Data_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Data_descriptor_,
      Data::default_instance_,
      Data_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Data));
  LifeStage_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_data_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Data_descriptor_, &Data::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_data_2eproto() {
  delete Data::default_instance_;
  delete Data_reflection_;
}

void protobuf_AddDesc_data_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ndata.proto\022\tprotosree\"\'\n\004Data\022\037\n\001s\030\001 \001"
    "(\0162\024.protosree.LifeStage*@\n\tLifeStage\022\013\n"
    "\007STUDENT\020\000\022\014\n\010EMPLOYED\020\001\022\013\n\007RETIRED\020\002\022\013\n"
    "\007EXPIRED\020\003", 130);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "data.proto", &protobuf_RegisterTypes);
  Data::default_instance_ = new Data();
  Data::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_data_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_data_2eproto {
  StaticDescriptorInitializer_data_2eproto() {
    protobuf_AddDesc_data_2eproto();
  }
} static_descriptor_initializer_data_2eproto_;
const ::google::protobuf::EnumDescriptor* LifeStage_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LifeStage_descriptor_;
}
bool LifeStage_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int Data::kSFieldNumber;
#endif  // !_MSC_VER

Data::Data()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Data::InitAsDefaultInstance() {
}

Data::Data(const Data& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Data::SharedCtor() {
  _cached_size_ = 0;
  s_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Data::~Data() {
  SharedDtor();
}

void Data::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Data::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Data::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Data_descriptor_;
}

const Data& Data::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_data_2eproto();
  return *default_instance_;
}

Data* Data::default_instance_ = NULL;

Data* Data::New() const {
  return new Data;
}

void Data::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    s_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Data::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protosree.LifeStage s = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protosree::LifeStage_IsValid(value)) {
            set_s(static_cast< ::protosree::LifeStage >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Data::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .protosree.LifeStage s = 1;
  if (has_s()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->s(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Data::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional .protosree.LifeStage s = 1;
  if (has_s()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->s(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Data::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protosree.LifeStage s = 1;
    if (has_s()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->s());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Data::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Data* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Data*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Data::MergeFrom(const Data& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_s()) {
      set_s(from.s());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Data::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Data::CopyFrom(const Data& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Data::IsInitialized() const {

  return true;
}

void Data::Swap(Data* other) {
  if (other != this) {
    std::swap(s_, other->s_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Data::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Data_descriptor_;
  metadata.reflection = Data_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protosree

// @@protoc_insertion_point(global_scope)
