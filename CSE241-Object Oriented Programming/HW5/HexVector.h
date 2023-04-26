#ifndef vectorHex
#define vectorHex
#include <vector>
#include "AbstractHex.h"

namespace Hex
{
using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    class HexVector : public AbstractHex
    {
        public:

    	HexVector( int xSize, int ySize);
    	virtual int check_valid( int x , int y ,int checkempty);
        virtual void setSize( const int& xSize , const int& ySize );
        virtual int& operator()( int x , int y );
        virtual const int& operator()( int x , int y ) const;

        HexVector& operator=(const HexVector& other);

         ~HexVector();

        private:

         std::vector<std::vector<int>>hex;
    };
}

#endif
