// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef AUTO_ODB_HXX
#define AUTO_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Auto.hpp"

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
  // Auto
  //
  template <>
  struct class_traits< ::Auto >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Auto >
  {
    public:
    typedef ::Auto object_type;
    typedef ::std::tr1::shared_ptr< ::Auto > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long int id_type;

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
  // Auto
  //
  template <typename A>
  struct pointer_query_columns< ::Auto, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // num
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    num_type_;

    static const num_type_ num;

    // color
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    color_type_;

    static const color_type_ color;

    // mark
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    mark_type_;

    static const mark_type_ mark;

    // person
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    person_type_;

    static const person_type_ person;
  };

  template <typename A>
  const typename pointer_query_columns< ::Auto, id_pgsql, A >::id_type_
  pointer_query_columns< ::Auto, id_pgsql, A >::
  id (A::table_name, "\"ID\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Auto, id_pgsql, A >::num_type_
  pointer_query_columns< ::Auto, id_pgsql, A >::
  num (A::table_name, "\"NUM\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Auto, id_pgsql, A >::color_type_
  pointer_query_columns< ::Auto, id_pgsql, A >::
  color (A::table_name, "\"COLOR\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Auto, id_pgsql, A >::mark_type_
  pointer_query_columns< ::Auto, id_pgsql, A >::
  mark (A::table_name, "\"MARK\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Auto, id_pgsql, A >::person_type_
  pointer_query_columns< ::Auto, id_pgsql, A >::
  person (A::table_name, "\"PERSONNEL_ID\"", 0);

  template <>
  class access::object_traits_impl< ::Auto, id_pgsql >:
    public access::object_traits< ::Auto >
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

      // num_
      //
      details::buffer num_value;
      std::size_t num_size;
      bool num_null;

      // color_
      //
      details::buffer color_value;
      std::size_t color_size;
      bool color_null;

      // mark_
      //
      details::buffer mark_value;
      std::size_t mark_size;
      bool mark_null;

      // person_
      //
      long long person_value;
      bool person_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct person_tag;

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
  class access::object_traits_impl< ::Auto, id_common >:
    public access::object_traits_impl< ::Auto, id_pgsql >
  {
  };

  // Auto
  //
  template <>
  struct alias_traits<
    ::Person,
    id_pgsql,
    access::object_traits_impl< ::Auto, id_pgsql >::person_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Auto, id_pgsql >
  {
    // person
    //
    typedef
    odb::alias_traits<
      ::Person,
      id_pgsql,
      access::object_traits_impl< ::Auto, id_pgsql >::person_tag>
    person_alias_;
  };

  template <typename A>
  struct query_columns< ::Auto, id_pgsql, A >:
    query_columns_base< ::Auto, id_pgsql >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // num
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    num_type_;

    static const num_type_ num;

    // color
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    color_type_;

    static const color_type_ color;

    // mark
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    mark_type_;

    static const mark_type_ mark;

    // person
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    person_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Person,
        id_pgsql,
        person_alias_ > >
    person_pointer_type_;

    struct person_type_: person_pointer_type_, person_column_type_
    {
      person_type_ (const char* t, const char* c, const char* conv)
        : person_column_type_ (t, c, conv)
      {
      }
    };

    static const person_type_ person;
  };

  template <typename A>
  const typename query_columns< ::Auto, id_pgsql, A >::id_type_
  query_columns< ::Auto, id_pgsql, A >::
  id (A::table_name, "\"ID\"", 0);

  template <typename A>
  const typename query_columns< ::Auto, id_pgsql, A >::num_type_
  query_columns< ::Auto, id_pgsql, A >::
  num (A::table_name, "\"NUM\"", 0);

  template <typename A>
  const typename query_columns< ::Auto, id_pgsql, A >::color_type_
  query_columns< ::Auto, id_pgsql, A >::
  color (A::table_name, "\"COLOR\"", 0);

  template <typename A>
  const typename query_columns< ::Auto, id_pgsql, A >::mark_type_
  query_columns< ::Auto, id_pgsql, A >::
  mark (A::table_name, "\"MARK\"", 0);

  template <typename A>
  const typename query_columns< ::Auto, id_pgsql, A >::person_type_
  query_columns< ::Auto, id_pgsql, A >::
  person (A::table_name, "\"PERSONNEL_ID\"", 0);
}

#include "Auto-odb.ixx"

#include <odb/post.hxx>

#endif // AUTO_ODB_HXX
