// file      : odb/mssql/no-id-object-result.hxx
// copyright : Copyright (c) 2009-2012 Code Synthesis Tools CC
// license   : ODB NCUEL; see accompanying LICENSE file

#ifndef ODB_MSSQL_NO_ID_OBJECT_RESULT_HXX
#define ODB_MSSQL_NO_ID_OBJECT_RESULT_HXX

#include <odb/pre.hxx>

#include <cstddef> // std::size_t

#include <odb/no-id-object-result.hxx>

#include <odb/details/shared-ptr.hxx>

#include <odb/mssql/version.hxx>
#include <odb/mssql/forward.hxx> // query
#include <odb/mssql/statement.hxx>

namespace odb
{
  namespace mssql
  {
    template <typename T>
    class no_id_object_result_impl: public odb::no_id_object_result_impl<T>
    {
    public:
      typedef odb::no_id_object_result_impl<T> base_type;

      typedef typename base_type::object_type object_type;
      typedef typename base_type::object_traits object_traits;

      typedef typename base_type::pointer_type pointer_type;
      typedef typename base_type::pointer_traits pointer_traits;

      typedef typename object_traits::statements_type statements_type;

      virtual
      ~no_id_object_result_impl ();

      no_id_object_result_impl (const query&,
                                details::shared_ptr<select_statement>,
                                statements_type&);

      virtual void
      load (object_type&);

      virtual void
      next ();

      virtual void
      cache ();

      virtual std::size_t
      size ();

      using base_type::current;

    private:
      typedef mssql::change_callback change_callback_type;

      static void
      change_callback (void* context);

    private:
      details::shared_ptr<select_statement> statement_;
      statements_type& statements_;
      bool can_load_;
      bool use_copy_;
      typename object_traits::image_type* image_copy_;
    };
  }
}

#include <odb/mssql/no-id-object-result.txx>

#include <odb/post.hxx>

#endif // ODB_MSSQL_NO_ID_OBJECT_RESULT_HXX