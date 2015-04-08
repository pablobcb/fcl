#include <list>
#include <algorithm>

namespace fcl
{
    template< 
        class NODE, 
        class OUTNODE, 
        template < class NODE, class A = std::allocator< NODE > > class COLLECTION
    > COLLECTION< OUTNODE > map (const COLLECTION< NODE>& collection, OUTNODE(*f)(const NODE&))
    {
        COLLECTION< OUTNODE > result;

        result.resize( collection.size() );

        typename COLLECTION< NODE >::const_iterator it;

        std::transform( collection.begin(), collection.end(), result.begin(), f );
        /*for( it = l.begin() ; it != l.end() ; ++it )
        {
            int elem = f(*it);
            result.push_back(elem);
        }*/
        
        return result;
    }

    template< 
        class NODE, 
        template < class NODE, class A = std::allocator< NODE > > class COLLECTION
    > void each (const COLLECTION< NODE>& collection, void(*f)(const NODE&))
    {
        typename COLLECTION< NODE >::const_iterator it;

        std::for_each( collection.begin(), collection.end(), f );
        /*for( it = l.begin() ; it != l.end() ; ++it )
        {
            int elem = f(*it);
            result.push_back(elem);
        }*/
        
    }

    template< 
        class NODE, 
        template < class NODE, class A = std::allocator< NODE > > class COLLECTION
    > COLLECTION< NODE > filter (const COLLECTION< NODE>& collection, bool(*f)(const NODE&))
    {
        COLLECTION< NODE > result;

        result.resize( collection.size() );

        typename COLLECTION< NODE >::const_iterator it;

        std::transform( collection.begin(), collection.end(), result.begin(), f );
        /*for( it = l.begin() ; it != l.end() ; ++it )
        {
            int elem = f(*it);
            result.push_back(elem);
        }*/
        
        return result;
    }
}
