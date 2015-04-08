#include <list>
#include <algorithm>

/* functional programming library designed to facilitate working with collections */
namespace fcl
{
    template< 
        class IN_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > void each ( const COLLECTION< IN_TYPE>& collection, void (*f) ( const IN_TYPE& ) )
    {
        typename COLLECTION< IN_TYPE >::const_iterator it;

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
            bool passedFilter = f(node);

            if (passedFilter)
                result.push_back(node);
        }
        
        return result;
    }


   template< 
        class IN_TYPE, 
        class OUT_TYPE, 
        template < class IN_TYPE, class A = std::allocator< IN_TYPE > > class COLLECTION
    > COLLECTION< OUT_TYPE > reduce (const COLLECTION< IN_TYPE >& collection, OUT_TYPE (*f) (const IN_TYPE&) )
    { 
        COLLECTION< IN_TYPE > result;

        typename COLLECTION< IN_TYPE >::const_iterator it;

        //std::copy_if( collection.begin(), collection.end(), result.begin(), f );
        for( it = collection.begin() ; it != collection.end() ; ++it )
        {
            IN_TYPE node = *it;
            bool passedFilter = f(node);

            if (passedFilter)
                result.push_back(node);
        }
        
        return result;
    }

}
