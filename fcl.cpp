#include <list>
#include <algorithm>

/* functional programming library designed to facilitate working with collections */
//TODO: take, drop, takeWhile, dropWhile
//TODO: alias map -> collect, find -> findOne, findALl -> filter
namespace fcl
{
    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > void each ( const COLLECTION< IN_TYPE>& collection, void (*f) ( const IN_TYPE& ) )
    {
         std::for_each( collection.begin(), collection.end(), f );
    }


    template< 
        class IN_TYPE, 
        class OUT_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > COLLECTION< OUT_TYPE > map (const COLLECTION< IN_TYPE >& collection, OUT_TYPE (*f) ( const IN_TYPE& ) )
    {
        COLLECTION< OUT_TYPE > result;

        result.resize( collection.size() );

        typename COLLECTION< IN_TYPE >::const_iterator it;

        std::transform( collection.begin(), collection.end(), result.begin(), f );
        /*for( it = l.begin() ; it != l.end() ; ++it )
        {
            int elem = f(*it);
            result.push_back(elem);
        }*/
        
        return result;
    }


    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > COLLECTION< IN_TYPE > filter (const COLLECTION< IN_TYPE >& collection, bool (*f) ( const IN_TYPE& ) )
    {
        COLLECTION< IN_TYPE > result;

        typename COLLECTION< IN_TYPE >::const_iterator it;

        //std::copy_if( collection.begin(), collection.end(), result.begin(), f );
        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;
            bool passedFilter = f( node );

            if (passedFilter)
                result.push_back( node );
        }
        
        return result;
    }
    

    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > IN_TYPE find (const COLLECTION< IN_TYPE >& collection, bool (*f) ( const IN_TYPE& ) )
    {
        IN_TYPE result = 0;

        typename COLLECTION< IN_TYPE >::const_iterator it;

        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;

            bool found = f( node );

            if ( found )
            {
                result = node;
                break;
            }
        }
        
        return result;
    }


    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > bool any (const COLLECTION< IN_TYPE >& collection, bool (*f) ( const IN_TYPE& ) )
    {

        typename COLLECTION< IN_TYPE >::const_iterator it;

        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;

            bool any = f( node );

            if ( any )
            {
                return true;
            }
        }
        
        return false;
    }

    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > bool all (const COLLECTION< IN_TYPE >& collection, bool (*f) ( const IN_TYPE& ) )
    {
        typename COLLECTION< IN_TYPE >::const_iterator it;

        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;

            bool satisfies = f( node );

            if ( !satisfies )
            {
                return false;
            }
        }
        
        return true;
    }


   template< 
        class IN_TYPE, 
        class OUT_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > OUT_TYPE reduce (const COLLECTION< IN_TYPE >& collection, 
        OUT_TYPE& initialValue, OUT_TYPE (*f) ( const OUT_TYPE&, const IN_TYPE& ) )
    { 
        OUT_TYPE result;

        result = initialValue;

        typename COLLECTION< IN_TYPE >::const_iterator it;

        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;
            result = f(result, node);
        }
        
        return result;
    }

}
