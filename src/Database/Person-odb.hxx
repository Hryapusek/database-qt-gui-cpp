// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Person.hpp"

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
  // Person
  //
  template <>
  struct class_traits< ::Person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Person >
  {
    public:
    typedef ::Person object_type;
    typedef ::std::tr1::shared_ptr< ::Person > pointer_type;
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
  // Person
  //
  template <typename A>
  struct query_columns< ::Person, id_pgsql, A >
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

    // firstName
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    firstName_type_;

    static const firstName_type_ firstName;

    // secondName
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    secondName_type_;

    static const secondName_type_ secondName;

    // fatherName
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::basic_string< char >,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    fatherName_type_;

    static const fatherName_type_ fatherName;
  };

  template <typename A>
  const typename query_columns< ::Person, id_pgsql, A >::id_type_
  query_columns< ::Person, id_pgsql, A >::
  id (A::table_name, "\"ID\"", 0);

  template <typename A>
  const typename query_columns< ::Person, id_pgsql, A >::firstName_type_
  query_columns< ::Person, id_pgsql, A >::
  firstName (A::table_name, "\"FIRST_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::Person, id_pgsql, A >::secondName_type_
  query_columns< ::Person, id_pgsql, A >::
  secondName (A::table_name, "\"LAST_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::Person, id_pgsql, A >::fatherName_type_
  query_columns< ::Person, id_pgsql, A >::
  fatherName (A::table_name, "\"PATHER_NAME\"", 0);

  template <typename A>
  struct pointer_query_columns< ::Person, id_pgsql, A >:
    query_columns< ::Person, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::Person, id_pgsql >:
    public access::object_traits< ::Person >
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

      // firstName_
      //
      details::buffer firstName_value;
      std::size_t firstName_size;
      bool firstName_null;

      // secondName_
      //
      details::buffer secondName_value;
      std::size_t secondName_size;
      bool secondName_null;

      // fatherName_
      //
      details::buffer fatherName_value;
      std::size_t fatherName_size;
      bool fatherName_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

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

    static const std::size_t column_count = 4UL;
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
  class access::object_traits_impl< ::Person, id_common >:
    public access::object_traits_impl< ::Person, id_pgsql >
  {
  };

  // Person
  //
}

#include "Person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX
