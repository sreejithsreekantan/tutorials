// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: data.proto

#ifndef PROTOBUF_data_2eproto__INCLUDED
#define PROTOBUF_data_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "minidata.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_data_2eproto();
void protobuf_AssignDesc_data_2eproto();
void protobuf_ShutdownFile_data_2eproto();

class Data;

// ===================================================================

class Data : public ::google::protobuf::Message {
 public:
  Data();
  virtual ~Data();

  Data(const Data& from);

  inline Data& operator=(const Data& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Data& default_instance();

  void Swap(Data* other);

  // implements Message ----------------------------------------------

  Data* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Data& from);
  void MergeFrom(const Data& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .MiniData m = 1;
  inline bool has_m() const;
  inline void clear_m();
  static const int kMFieldNumber = 1;
  inline const ::MiniData& m() const;
  inline ::MiniData* mutable_m();
  inline ::MiniData* release_m();
  inline void set_allocated_m(::MiniData* m);

  // @@protoc_insertion_point(class_scope:Data)
 private:
  inline void set_has_m();
  inline void clear_has_m();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::MiniData* m_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_data_2eproto();
  friend void protobuf_AssignDesc_data_2eproto();
  friend void protobuf_ShutdownFile_data_2eproto();

  void InitAsDefaultInstance();
  static Data* default_instance_;
};
// ===================================================================


// ===================================================================

// Data

// optional .MiniData m = 1;
inline bool Data::has_m() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Data::set_has_m() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Data::clear_has_m() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Data::clear_m() {
  if (m_ != NULL) m_->::MiniData::Clear();
  clear_has_m();
}
inline const ::MiniData& Data::m() const {
  return m_ != NULL ? *m_ : *default_instance_->m_;
}
inline ::MiniData* Data::mutable_m() {
  set_has_m();
  if (m_ == NULL) m_ = new ::MiniData;
  return m_;
}
inline ::MiniData* Data::release_m() {
  clear_has_m();
  ::MiniData* temp = m_;
  m_ = NULL;
  return temp;
}
inline void Data::set_allocated_m(::MiniData* m) {
  delete m_;
  m_ = m;
  if (m) {
    set_has_m();
  } else {
    clear_has_m();
  }
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_data_2eproto__INCLUDED
