// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef JOURNAL_ROW_ODB_HXX
#define JOURNAL_ROW_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "JournalRow.hpp"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/tr1/wrapper-traits.hxx>
#include <odb/tr1/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // JournalRow
  //
  template <>
  struct class_traits< ::JournalRow >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::JournalRow >
  {
    public:
    typedef ::JournalRow object_type;
    typedef ::std::tr1::shared_ptr< ::JournalRow > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::JournalRow::Id_t id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // JournalRow
  //
  template <typename A>
  struct pointer_query_columns< ::JournalRow, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::JournalRow::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // timeOut
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::optional< long int >,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    timeOut_type_;

    static const timeOut_type_ timeOut;

    // timeIn
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::optional< long int >,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    timeIn_type_;

    static const timeIn_type_ timeIn;

    // route
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::Route::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    route_type_;

    static const route_type_ route;

    // auto_
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::Auto::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    auto__type_;

    static const auto__type_ auto_;
  };

  template <typename A>
  const typename pointer_query_columns< ::JournalRow, id_pgsql, A >::id_type_
  pointer_query_columns< ::JournalRow, id_pgsql, A >::
  id (A::table_name, "\"ID\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::JournalRow, id_pgsql, A >::timeOut_type_
  pointer_query_columns< ::JournalRow, id_pgsql, A >::
  timeOut (A::table_name, "\"TIME_OUT\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::JournalRow, id_pgsql, A >::timeIn_type_
  pointer_query_columns< ::JournalRow, id_pgsql, A >::
  timeIn (A::table_name, "\"TIME_IN\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::JournalRow, id_pgsql, A >::route_type_
  pointer_query_columns< ::JournalRow, id_pgsql, A >::
  route (A::table_name, "\"ROUTE_ID\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::JournalRow, id_pgsql, A >::auto__type_
  pointer_query_columns< ::JournalRow, id_pgsql, A >::
  auto_ (A::table_name, "\"AUTO_ID\"", 0);

  template <>
  class access::object_traits_impl< ::JournalRow, id_pgsql >:
    public access::object_traits< ::JournalRow >
  {
    public:
    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;

      // timeOut_
      //
      long long timeOut_value;
      bool timeOut_null;

      // timeIn_
      //
      long long timeIn_value;
      bool timeIn_null;

      // route_
      //
      long long route_value;
      bool route_null;

      // auto_
      //
      long long auto_value;
      bool auto_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct route_tag;
    struct auto__tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 5UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::JournalRow, id_common >:
    public access::object_traits_impl< ::JournalRow, id_pgsql >
  {
  };

  // JournalRow
  //
  template <>
  struct alias_traits<
    ::Route,
    id_pgsql,
    access::object_traits_impl< ::JournalRow, id_pgsql >::route_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Auto,
    id_pgsql,
    access::object_traits_impl< ::JournalRow, id_pgsql >::auto__tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::JournalRow, id_pgsql >
  {
    // route
    //
    typedef
    odb::alias_traits<
      ::Route,
      id_pgsql,
      access::object_traits_impl< ::JournalRow, id_pgsql >::route_tag>
    route_alias_;

    // auto_
    //
    typedef
    odb::alias_traits<
      ::Auto,
      id_pgsql,
      access::object_traits_impl< ::JournalRow, id_pgsql >::auto__tag>
    auto__alias_;
  };

  template <typename A>
  struct query_columns< ::JournalRow, id_pgsql, A >:
    query_columns_base< ::JournalRow, id_pgsql >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::JournalRow::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // timeOut
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::optional< long int >,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    timeOut_type_;

    static const timeOut_type_ timeOut;

    // timeIn
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::optional< long int >,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    timeIn_type_;

    static const timeIn_type_ timeIn;

    // route
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::Route::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    route_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Route,
        id_pgsql,
        route_alias_ > >
    route_pointer_type_;

    struct route_type_: route_pointer_type_, route_column_type_
    {
      route_type_ (const char* t, const char* c, const char* conv)
        : route_column_type_ (t, c, conv)
      {
      }
    };

    static const route_type_ route;

    // auto_
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::Auto::Id_t,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    auto__column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Auto,
        id_pgsql,
        auto__alias_ > >
    auto__pointer_type_;

    struct auto__type_: auto__pointer_type_, auto__column_type_
    {
      auto__type_ (const char* t, const char* c, const char* conv)
        : auto__column_type_ (t, c, conv)
      {
      }
    };

    static const auto__type_ auto_;
  };

  template <typename A>
  const typename query_columns< ::JournalRow, id_pgsql, A >::id_type_
  query_columns< ::JournalRow, id_pgsql, A >::
  id (A::table_name, "\"ID\"", 0);

  template <typename A>
  const typename query_columns< ::JournalRow, id_pgsql, A >::timeOut_type_
  query_columns< ::JournalRow, id_pgsql, A >::
  timeOut (A::table_name, "\"TIME_OUT\"", 0);

  template <typename A>
  const typename query_columns< ::JournalRow, id_pgsql, A >::timeIn_type_
  query_columns< ::JournalRow, id_pgsql, A >::
  timeIn (A::table_name, "\"TIME_IN\"", 0);

  template <typename A>
  const typename query_columns< ::JournalRow, id_pgsql, A >::route_type_
  query_columns< ::JournalRow, id_pgsql, A >::
  route (A::table_name, "\"ROUTE_ID\"", 0);

  template <typename A>
  const typename query_columns< ::JournalRow, id_pgsql, A >::auto__type_
  query_columns< ::JournalRow, id_pgsql, A >::
  auto_ (A::table_name, "\"AUTO_ID\"", 0);
}

#include "JournalRow-odb.ixx"

#include <odb/post.hxx>

#endif // JOURNAL_ROW_ODB_HXX
