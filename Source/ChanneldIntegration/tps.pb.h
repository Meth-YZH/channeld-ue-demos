// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tps.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_tps_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_tps_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021005 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
#include "unreal_common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_tps_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_tps_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tps_2eproto;
namespace tpspb {
class TestRepChannelData;
struct TestRepChannelDataDefaultTypeInternal;
extern TestRepChannelDataDefaultTypeInternal _TestRepChannelData_default_instance_;
class TestRepChannelData_SceneComponentStatesEntry_DoNotUse;
struct TestRepChannelData_SceneComponentStatesEntry_DoNotUseDefaultTypeInternal;
extern TestRepChannelData_SceneComponentStatesEntry_DoNotUseDefaultTypeInternal _TestRepChannelData_SceneComponentStatesEntry_DoNotUse_default_instance_;
}  // namespace tpspb
PROTOBUF_NAMESPACE_OPEN
template<> ::tpspb::TestRepChannelData* Arena::CreateMaybeMessage<::tpspb::TestRepChannelData>(Arena*);
template<> ::tpspb::TestRepChannelData_SceneComponentStatesEntry_DoNotUse* Arena::CreateMaybeMessage<::tpspb::TestRepChannelData_SceneComponentStatesEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tpspb {

// ===================================================================

class TestRepChannelData_SceneComponentStatesEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TestRepChannelData_SceneComponentStatesEntry_DoNotUse, 
    uint32_t, ::channeldpb::SceneComponentState,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT32,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TestRepChannelData_SceneComponentStatesEntry_DoNotUse, 
    uint32_t, ::channeldpb::SceneComponentState,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT32,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> SuperType;
  TestRepChannelData_SceneComponentStatesEntry_DoNotUse();
  explicit PROTOBUF_CONSTEXPR TestRepChannelData_SceneComponentStatesEntry_DoNotUse(
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);
  explicit TestRepChannelData_SceneComponentStatesEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const TestRepChannelData_SceneComponentStatesEntry_DoNotUse& other);
  static const TestRepChannelData_SceneComponentStatesEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const TestRepChannelData_SceneComponentStatesEntry_DoNotUse*>(&_TestRepChannelData_SceneComponentStatesEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(void*) { return true; }
  static bool ValidateValue(void*) { return true; }
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  friend struct ::TableStruct_tps_2eproto;
};

// -------------------------------------------------------------------

class TestRepChannelData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tpspb.TestRepChannelData) */ {
 public:
  inline TestRepChannelData() : TestRepChannelData(nullptr) {}
  ~TestRepChannelData() override;
  explicit PROTOBUF_CONSTEXPR TestRepChannelData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TestRepChannelData(const TestRepChannelData& from);
  TestRepChannelData(TestRepChannelData&& from) noexcept
    : TestRepChannelData() {
    *this = ::std::move(from);
  }

  inline TestRepChannelData& operator=(const TestRepChannelData& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestRepChannelData& operator=(TestRepChannelData&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TestRepChannelData& default_instance() {
    return *internal_default_instance();
  }
  static inline const TestRepChannelData* internal_default_instance() {
    return reinterpret_cast<const TestRepChannelData*>(
               &_TestRepChannelData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TestRepChannelData& a, TestRepChannelData& b) {
    a.Swap(&b);
  }
  inline void Swap(TestRepChannelData* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestRepChannelData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TestRepChannelData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TestRepChannelData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TestRepChannelData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TestRepChannelData& from) {
    TestRepChannelData::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TestRepChannelData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tpspb.TestRepChannelData";
  }
  protected:
  explicit TestRepChannelData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kSceneComponentStatesFieldNumber = 1,
  };
  // map<uint32, .channeldpb.SceneComponentState> sceneComponentStates = 1;
  int scenecomponentstates_size() const;
  private:
  int _internal_scenecomponentstates_size() const;
  public:
  void clear_scenecomponentstates();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >&
      _internal_scenecomponentstates() const;
  ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >*
      _internal_mutable_scenecomponentstates();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >&
      scenecomponentstates() const;
  ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >*
      mutable_scenecomponentstates();

  // @@protoc_insertion_point(class_scope:tpspb.TestRepChannelData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::MapField<
        TestRepChannelData_SceneComponentStatesEntry_DoNotUse,
        uint32_t, ::channeldpb::SceneComponentState,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT32,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> scenecomponentstates_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tps_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TestRepChannelData

// map<uint32, .channeldpb.SceneComponentState> sceneComponentStates = 1;
inline int TestRepChannelData::_internal_scenecomponentstates_size() const {
  return _impl_.scenecomponentstates_.size();
}
inline int TestRepChannelData::scenecomponentstates_size() const {
  return _internal_scenecomponentstates_size();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >&
TestRepChannelData::_internal_scenecomponentstates() const {
  return _impl_.scenecomponentstates_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >&
TestRepChannelData::scenecomponentstates() const {
  // @@protoc_insertion_point(field_map:tpspb.TestRepChannelData.sceneComponentStates)
  return _internal_scenecomponentstates();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >*
TestRepChannelData::_internal_mutable_scenecomponentstates() {
  return _impl_.scenecomponentstates_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< uint32_t, ::channeldpb::SceneComponentState >*
TestRepChannelData::mutable_scenecomponentstates() {
  // @@protoc_insertion_point(field_mutable_map:tpspb.TestRepChannelData.sceneComponentStates)
  return _internal_mutable_scenecomponentstates();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tpspb

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_tps_2eproto
