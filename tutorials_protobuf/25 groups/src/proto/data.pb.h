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
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_data_2eproto();
void protobuf_AssignDesc_data_2eproto();
void protobuf_ShutdownFile_data_2eproto();

class Data;
class Data_MiniData;

// ===================================================================

class Data_MiniData : public ::google::protobuf::Message {
 public:
  Data_MiniData();
  virtual ~Data_MiniData();

  Data_MiniData(const Data_MiniData& from);

  inline Data_MiniData& operator=(const Data_MiniData& from) {
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
  static const Data_MiniData& default_instance();

  void Swap(Data_MiniData* other);

  // implements Message ----------------------------------------------

  Data_MiniData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Data_MiniData& from);
  void MergeFrom(const Data_MiniData& from);
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

  // optional int32 i = 1;
  inline bool has_i() const;
  inline void clear_i();
  static const int kIFieldNumber = 1;
  inline ::google::protobuf::int32 i() const;
  inline void set_i(::google::protobuf::int32 value);

  // optional bool b = 2;
  inline bool has_b() const;
  inline void clear_b();
  static const int kBFieldNumber = 2;
  inline bool b() const;
  inline void set_b(bool value);

  // @@protoc_insertion_point(class_scope:Data.MiniData)
 private:
  inline void set_has_i();
  inline void clear_has_i();
  inline void set_has_b();
  inline void clear_has_b();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 i_;
  bool b_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_data_2eproto();
  friend void protobuf_AssignDesc_data_2eproto();
  friend void protobuf_ShutdownFile_data_2eproto();

  void InitAsDefaultInstance();
  static Data_MiniData* default_instance_;
};
// -------------------------------------------------------------------

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

  typedef Data_MiniData MiniData;

  // accessors -------------------------------------------------------

  // optional group MiniData = 1 {
  inline bool has_minidata() const;
  inline void clear_minidata();
  static const int kMinidataFieldNumber = 1;
  inline const ::Data_MiniData& minidata() const;
  inline ::Data_MiniData* mutable_minidata();
  inline ::Data_MiniData* release_minidata();
  inline void set_allocated_minidata(::Data_MiniData* minidata);

  // @@protoc_insertion_point(class_scope:Data)
 private:
  inline void set_has_minidata();
  inline void clear_has_minidata();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::Data_MiniData* minidata_;

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

// Data_MiniData

// optional int32 i = 1;
inline bool Data_MiniData::has_i() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Data_MiniData::set_has_i() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Data_MiniData::clear_has_i() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Data_MiniData::clear_i() {
  i_ = 0;
  clear_has_i();
}
inline ::google::protobuf::int32 Data_MiniData::i() const {
  return i_;
}
inline void Data_MiniData::set_i(::google::protobuf::int32 value) {
  set_has_i();
  i_ = value;
}

// optional bool b = 2;
inline bool Data_MiniData::has_b() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Data_MiniData::set_has_b() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Data_MiniData::clear_has_b() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Data_MiniData::clear_b() {
  b_ = false;
  clear_has_b();
}
inline bool Data_MiniData::b() const {
  return b_;
}
inline void Data_MiniData::set_b(bool value) {
  set_has_b();
  b_ = value;
}

// -------------------------------------------------------------------

// Data

// optional group MiniData = 1 {
inline bool Data::has_minidata() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Data::set_has_minidata() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Data::clear_has_minidata() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Data::clear_minidata() {
  if (minidata_ != NULL) minidata_->::Data_MiniData::Clear();
  clear_has_minidata();
}
inline const ::Data_MiniData& Data::minidata() const {
  return minidata_ != NULL ? *minidata_ : *default_instance_->minidata_;
}
inline ::Data_MiniData* Data::mutable_minidata() {
  set_has_minidata();
  if (minidata_ == NULL) minidata_ = new ::Data_MiniData;
  return minidata_;
}
inline ::Data_MiniData* Data::release_minidata() {
  clear_has_minidata();
  ::Data_MiniData* temp = minidata_;
  minidata_ = NULL;
  return temp;
}
inline void Data::set_allocated_minidata(::Data_MiniData* minidata) {
  delete minidata_;
  minidata_ = minidata;
  if (minidata) {
    set_has_minidata();
  } else {
    clear_has_minidata();
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
