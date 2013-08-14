// file      : odb/mssql/database.ixx
// copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
// license   : ODB NCUEL; see accompanying LICENSE file

#include <odb/mssql/transaction.hxx>

namespace odb
{
  namespace mssql
  {
    inline connection_ptr database::
    connection ()
    {
      // Go through the virtual connection_() function instead of
      // directly to allow overriding.
      //
      return connection_ptr (
        static_cast<mssql::connection*> (connection_ ()));
    }

    template <typename T>
    inline typename object_traits<T>::id_type database::
    persist (T& obj)
    {
      return persist_<T, id_mssql> (obj);
    }

    template <typename T>
    inline typename object_traits<T>::id_type database::
    persist (T* p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      return persist_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline typename object_traits<T>::id_type database::
    persist (const P<T>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      return persist_<T, id_mssql> (pobj);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline typename object_traits<T>::id_type database::
    persist (const P<T, A1>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      return persist_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline typename object_traits<T>::id_type database::
    persist (P<T>& p)
    {
      const P<T>& cr (p);
      return persist<T, P> (cr);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline typename object_traits<T>::id_type database::
    persist (P<T, A1>& p)
    {
      const P<T, A1>& cr (p);
      return persist<T, A1, P> (cr);
    }

    template <typename T>
    inline typename object_traits<T>::id_type database::
    persist (const typename object_traits<T>::pointer_type& pobj)
    {
      return persist_<T, id_mssql> (pobj);
    }

    template <typename T>
    inline typename object_traits<T>::pointer_type database::
    load (const typename object_traits<T>::id_type& id)
    {
      return load_<T, id_mssql> (id);
    }

    template <typename T>
    inline void database::
    load (const typename object_traits<T>::id_type& id, T& obj)
    {
      return load_<T, id_mssql> (id, obj);
    }

    template <typename T>
    inline void database::
    load (T& obj, section& s)
    {
      return load_<T, id_mssql> (obj, s);
    }

    template <typename T>
    inline typename object_traits<T>::pointer_type database::
    find (const typename object_traits<T>::id_type& id)
    {
      return find_<T, id_mssql> (id);
    }

    template <typename T>
    inline bool database::
    find (const typename object_traits<T>::id_type& id, T& obj)
    {
      return find_<T, id_mssql> (id, obj);
    }

    template <typename T>
    inline void database::
    reload (T& obj)
    {
      reload_<T, id_mssql> (obj);
    }

    template <typename T>
    inline void database::
    reload (T* p)
    {
      reload<T> (*p);
    }

    template <typename T, template <typename> class P>
    inline void database::
    reload (const P<T>& p)
    {
      reload (odb::pointer_traits< P<T> >::get_ref (p));
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    reload (const P<T, A1>& p)
    {
      reload (odb::pointer_traits< P<T, A1> >::get_ref (p));
    }

    template <typename T, template <typename> class P>
    inline void database::
    reload (P<T>& p)
    {
      reload (odb::pointer_traits< P<T> >::get_ref (p));
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    reload (P<T, A1>& p)
    {
      reload (odb::pointer_traits< P<T, A1> >::get_ref (p));
    }

    template <typename T>
    inline void database::
    reload (const typename object_traits<T>::pointer_type& pobj)
    {
      typedef typename object_traits<T>::pointer_type pointer_type;

      reload (odb::pointer_traits<pointer_type>::get_ref (pobj));
    }

    template <typename T>
    inline void database::
    update (T& obj)
    {
      update_<T, id_mssql> (obj);
    }

    template <typename T>
    inline void database::
    update (T* p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      update_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline void database::
    update (const P<T>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      update_<T, id_mssql> (pobj);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    update (const P<T, A1>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      update_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline void database::
    update (P<T>& p)
    {
      const P<T>& cr (p);
      update<T, P> (cr);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    update (P<T, A1>& p)
    {
      const P<T, A1>& cr (p);
      update<T, A1, P> (cr);
    }

    template <typename T>
    inline void database::
    update (const typename object_traits<T>::pointer_type& pobj)
    {
      update_<T, id_mssql> (pobj);
    }

    template <typename T>
    inline void database::
    update (const T& obj, const section& s)
    {
      update_<T, id_mssql> (obj, s);
    }

    template <typename T>
    inline void database::
    erase (const typename object_traits<T>::id_type& id)
    {
      return erase_<T, id_mssql> (id);
    }

    template <typename T>
    inline void database::
    erase (T& obj)
    {
      return erase_<T, id_mssql> (obj);
    }

    template <typename T>
    inline void database::
    erase (T* p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      erase_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline void database::
    erase (const P<T>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      erase_<T, id_mssql> (pobj);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    erase (const P<T, A1>& p)
    {
      typedef typename object_traits<T>::pointer_type object_pointer;

      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const object_pointer& pobj (p);

      erase_<T, id_mssql> (pobj);
    }

    template <typename T, template <typename> class P>
    inline void database::
    erase (P<T>& p)
    {
      const P<T>& cr (p);
      erase<T, P> (cr);
    }

    template <typename T, typename A1, template <typename, typename> class P>
    inline void database::
    erase (P<T, A1>& p)
    {
      const P<T, A1>& cr (p);
      erase<T, A1, P> (cr);
    }

    template <typename T>
    inline void database::
    erase (const typename object_traits<T>::pointer_type& pobj)
    {
      erase_<T, id_mssql> (pobj);
    }

    template <typename T>
    inline unsigned long long database::
    erase_query ()
    {
      // T is always object_type.
      //
      return erase_query<T> (mssql::query_base ());
    }

    template <typename T>
    inline unsigned long long database::
    erase_query (const char* q)
    {
      // T is always object_type.
      //
      return erase_query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline unsigned long long database::
    erase_query (const std::string& q)
    {
      // T is always object_type.
      //
      return erase_query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline unsigned long long database::
    erase_query (const mssql::query_base& q)
    {
      // T is always object_type.
      //
      return object_traits_impl<T, id_mssql>::erase_query (*this, q);
    }

    template <typename T>
    inline unsigned long long database::
    erase_query (const odb::query_base& q)
    {
      // Translate to native query.
      //
      return erase_query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline result<T> database::
    query ()
    {
      return query<T> (mssql::query_base ());
    }

    template <typename T>
    inline result<T> database::
    query (const char* q)
    {
      return query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline result<T> database::
    query (const std::string& q)
    {
      return query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline result<T> database::
    query (const mssql::query_base& q)
    {
      // T is always object_type. We also don't need to check for transaction
      // here; object_traits::query () does this.
      //
      return query_<T, id_mssql>::call (*this, q);
    }

    template <typename T>
    inline result<T> database::
    query (const odb::query_base& q)
    {
      // Translate to native query.
      //
      return query<T> (mssql::query_base (q));
    }

    template <typename T>
    inline prepared_query<T> database::
    prepare_query (const char* n, const char* q)
    {
      return prepare_query<T> (n, mssql::query_base (q));
    }

    template <typename T>
    inline prepared_query<T> database::
    prepare_query (const char* n, const std::string& q)
    {
      return prepare_query<T> (n, mssql::query_base (q));
    }

    template <typename T>
    inline prepared_query<T> database::
    prepare_query (const char* n, const mssql::query_base& q)
    {
      // Throws if not in transaction.
      //
      mssql::connection& c (transaction::current ().connection ());
      return c.prepare_query<T> (n, q);
    }

    template <typename T>
    inline prepared_query<T> database::
    prepare_query (const char* n, const odb::query_base& q)
    {
      // Translate to native query.
      //
      return prepare_query<T> (n, mssql::query_base (q));
    }
  }
}
