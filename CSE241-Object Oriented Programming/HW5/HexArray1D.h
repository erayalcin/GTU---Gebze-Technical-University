#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include "AbstractHex.h"

namespace Hex
{
using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    class HexArray1D : public AbstractHex
    {
        public:
    	HexArray1D();
    	HexArray1D( int xSize, int ySize);
    	HexArray1D( const HexArray1D& other);


    	virtual int check_valid( int x , int y ,int checkempty);
        virtual void setSize( const int& xSize , const int& ySize );
        virtual int& operator()( int x , int y );
        virtual const int& operator()( int x , int y ) const;



         ~HexArray1D();

        private:

            int* hex;
    };
}

#endif
