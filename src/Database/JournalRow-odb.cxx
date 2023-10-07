// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "JournalRow-odb.hxx"
#include "Auto-odb.hxx"
#include "Person-odb.hxx"
#include "Route-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/simple-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/simple-object-result.hxx>

namespace odb
{
  // JournalRow
  //

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  persist_statement_name[] = "persist_JournalRow";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  find_statement_name[] = "find_JournalRow";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  update_statement_name[] = "update_JournalRow";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  erase_statement_name[] = "erase_JournalRow";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  query_statement_name[] = "query_JournalRow";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::
  erase_query_statement_name[] = "erase_query_JournalRow";

  const unsigned int access::object_traits_impl< ::JournalRow, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::timestamp_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::JournalRow, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::JournalRow, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::timestamp_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const char alias_traits<  ::Route,
    id_pgsql,
    access::object_traits_impl< ::JournalRow, id_pgsql >::route_tag>::
  table_name[] = "\"ROUTE_ID\"";

  const char alias_traits<  ::Auto,
    id_pgsql,
    access::object_traits_impl< ::JournalRow, id_pgsql >::auto__tag>::
  table_name[] = "\"AUTO_ID\"";

  struct access::object_traits_impl< ::JournalRow, id_pgsql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      pgsql::connection&,
      image_type&,
      id_image_type&,
      pgsql::binding&,
      pgsql::binding&,
      pgsql::native_binding&,
      const unsigned int*)
    {
    }
  };

  access::object_traits_impl< ::JournalRow, id_pgsql >::id_type
  access::object_traits_impl< ::JournalRow, id_pgsql >::
  id (const id_image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          long int,
          pgsql::id_bigint >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::JournalRow, id_pgsql >::id_type
  access::object_traits_impl< ::JournalRow, id_pgsql >::
  id (const image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          long int,
          pgsql::id_bigint >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::JournalRow, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = 0;

    // timeOut_
    //
    t[1UL] = 0;

    // timeIn_
    //
    t[2UL] = 0;

    // route_
    //
    t[3UL] = 0;

    // auto_
    //
    t[4UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = pgsql::bind::bigint;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // timeOut_
    //
    b[n].type = pgsql::bind::timestamp;
    b[n].buffer = &i.timeOut_value;
    b[n].is_null = &i.timeOut_null;
    n++;

    // timeIn_
    //
    b[n].type = pgsql::bind::timestamp;
    b[n].buffer = &i.timeIn_value;
    b[n].is_null = &i.timeIn_null;
    n++;

    // route_
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.route_value;
    b[n].is_null = &i.route_null;
    n++;

    // auto_
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.auto_value;
    b[n].is_null = &i.auto_null;
    n++;
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::JournalRow, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // timeOut_
    //
    {
      // From JournalRow.hpp:47:14
      ::odb::nullable< long int > const& v =
        o.timeOut ();

      bool is_null (true);
      pgsql::value_traits<
          ::odb::nullable< long int >,
          pgsql::id_timestamp >::set_image (
        i.timeOut_value, is_null, v);
      i.timeOut_null = is_null;
    }

    // timeIn_
    //
    {
      // From JournalRow.hpp:50:14
      ::odb::nullable< long int > const& v =
        o.timeIn ();

      bool is_null (true);
      pgsql::value_traits<
          ::odb::nullable< long int >,
          pgsql::id_timestamp >::set_image (
        i.timeIn_value, is_null, v);
      i.timeIn_null = is_null;
    }

    // route_
    //
    {
      ::std::tr1::shared_ptr< ::Route > const& v =
        o.route_;

      typedef object_traits< ::Route > obj_traits;
      typedef odb::pointer_traits< ::std::tr1::shared_ptr< ::Route > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i.route_value, is_null, id);
        i.route_null = is_null;
      }
      else
        i.route_null = true;
    }

    // auto_
    //
    {
      ::std::tr1::shared_ptr< ::Auto > const& v =
        o.auto_;

      typedef object_traits< ::Auto > obj_traits;
      typedef odb::pointer_traits< ::std::tr1::shared_ptr< ::Auto > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i.auto_value, is_null, id);
        i.auto_null = is_null;
      }
      else
        i.auto_null = true;
    }

    return grew;
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      // From JournalRow.hpp:44:35
      long int v;

      pgsql::value_traits<
          long int,
          pgsql::id_bigint >::set_value (
        v,
        i.id_value,
        i.id_null);

      // From JournalRow.hpp:44:35
      o.id (v);
    }

    // timeOut_
    //
    {
      // From JournalRow.hpp:47:14
      ::odb::nullable< long int > v;

      pgsql::value_traits<
          ::odb::nullable< long int >,
          pgsql::id_timestamp >::set_value (
        v,
        i.timeOut_value,
        i.timeOut_null);

      // From JournalRow.hpp:47:14
      o.timeOut (v);
    }

    // timeIn_
    //
    {
      // From JournalRow.hpp:50:14
      ::odb::nullable< long int > v;

      pgsql::value_traits<
          ::odb::nullable< long int >,
          pgsql::id_timestamp >::set_value (
        v,
        i.timeIn_value,
        i.timeIn_null);

      // From JournalRow.hpp:50:14
      o.timeIn (v);
    }

    // route_
    //
    {
      ::std::tr1::shared_ptr< ::Route >& v =
        o.route_;

      typedef object_traits< ::Route > obj_traits;
      typedef odb::pointer_traits< ::std::tr1::shared_ptr< ::Route > > ptr_traits;

      if (i.route_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i.route_value,
          i.route_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<pgsql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // auto_
    //
    {
      ::std::tr1::shared_ptr< ::Auto >& v =
        o.auto_;

      typedef object_traits< ::Auto > obj_traits;
      typedef odb::pointer_traits< ::std::tr1::shared_ptr< ::Auto > > ptr_traits;

      if (i.auto_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i.auto_value,
          i.auto_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<pgsql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      pgsql::value_traits<
          long int,
          pgsql::id_bigint >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::persist_statement[] =
  "INSERT INTO \"JOURNAL\" "
  "(\"ID\", "
  "\"TIME_OUT\", "
  "\"TIME_IN\", "
  "\"ROUTE_ID\", "
  "\"AUTO_ID\") "
  "VALUES "
  "(DEFAULT, $1, $2, $3, $4) "
  "RETURNING \"ID\"";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::find_statement[] =
  "SELECT "
  "\"JOURNAL\".\"ID\", "
  "\"JOURNAL\".\"TIME_OUT\", "
  "\"JOURNAL\".\"TIME_IN\", "
  "\"JOURNAL\".\"ROUTE_ID\", "
  "\"JOURNAL\".\"AUTO_ID\" "
  "FROM \"JOURNAL\" "
  "WHERE \"JOURNAL\".\"ID\"=$1";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::update_statement[] =
  "UPDATE \"JOURNAL\" "
  "SET "
  "\"TIME_OUT\"=$1, "
  "\"TIME_IN\"=$2, "
  "\"ROUTE_ID\"=$3, "
  "\"AUTO_ID\"=$4 "
  "WHERE \"ID\"=$5";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::erase_statement[] =
  "DELETE FROM \"JOURNAL\" "
  "WHERE \"ID\"=$1";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::query_statement[] =
  "SELECT\n"
  "\"JOURNAL\".\"ID\",\n"
  "\"JOURNAL\".\"TIME_OUT\",\n"
  "\"JOURNAL\".\"TIME_IN\",\n"
  "\"JOURNAL\".\"ROUTE_ID\",\n"
  "\"JOURNAL\".\"AUTO_ID\"\n"
  "FROM \"JOURNAL\"\n"
  "LEFT JOIN \"ROUTES\" AS \"ROUTE_ID\" ON \"ROUTE_ID\".\"ID\"=\"JOURNAL\".\"ROUTE_ID\"\n"
  "LEFT JOIN \"AUTO\" AS \"AUTO_ID\" ON \"AUTO_ID\".\"ID\"=\"JOURNAL\".\"AUTO_ID\"";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"JOURNAL\"";

  const char access::object_traits_impl< ::JournalRow, id_pgsql >::table_name[] =
  "\"JOURNAL\"";

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    // From JournalRow.hpp:44:35
    obj.id (id (sts.id_image ()));

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;
    using pgsql::update_statement;

    callback (db, obj, callback_event::pre_update);

    pgsql::transaction& tr (pgsql::transaction::current ());
    pgsql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    // From JournalRow.hpp:44:35
    const id_type& id (
      obj.id ());
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::JournalRow, id_pgsql >::
  erase (database& db, const id_type& id)
  {
    using namespace pgsql;

    ODB_POTENTIALLY_UNUSED (db);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::JournalRow, id_pgsql >::pointer_type
  access::object_traits_impl< ::JournalRow, id_pgsql >::
  find (database& db, const id_type& id)
  {
    using namespace pgsql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::JournalRow, id_pgsql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::JournalRow, id_pgsql >::
  reload (database& db, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    // From JournalRow.hpp:44:35
    const id_type& id  (
      obj.id ());

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::JournalRow, id_pgsql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace pgsql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::JournalRow, id_pgsql >::object_type >
  access::object_traits_impl< ::JournalRow, id_pgsql >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        text,
        true,
        true,
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) pgsql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::JournalRow, id_pgsql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      erase_query_statement_name,
      text,
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>