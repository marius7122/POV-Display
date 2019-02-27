#ifndef MODELS_H
#define MODELS_H

namespace models 
{
    int letterLen(int l)
    { 
        if(l >= 'A' && l <= 'Z')
        {
            if(l != 'I')
                return 5;
            return 3;   // for letter i
        }

        if(l == '!')
            return 3;

        return 0;
    }


    int A[] = {
		127,	//001111111
		136,	//010001000
		264,	//100001000
		136,	//010001000
		127,	//001111111
    };

    int B[] = {
		511,	//111111111
		273,	//100010001
		273,	//100010001
		273,	//100010001
		238,	//011101110
    };

    int C[] = {
		254,	//011111110
		257,	//100000001
		257,	//100000001
		257,	//100000001
		130,	//010000010
    };

    int D[] = {
		511,	//111111111
		257,	//100000001
		257,	//100000001
		257,	//100000001
		254,	//011111110
    };

    int E[] = {
		511,	//111111111
		273,	//100010001
		273,	//100010001
		273,	//100010001
		273,	//100010001
    };

    int F[] = {
		511,	//111111111
		272,	//100010000
		272,	//100010000
		272,	//100010000
		272,	//100010000
    };

    int G[] = {
		254,	//011111110
		257,	//100000001
		265,	//100001001
		265,	//100001001
		142,	//010001110
    };

    int H[] = {
		511,	//111111111
		16,	    //000010000
		16,	    //000010000
		16,	    //000010000
		511,	//111111111
    };

    int I[] = {
		0,	    //000000000
		511,		//111111111
		0,	    //000000000
    };

    int J[] = {
		258,	//100000010
		257,	//100000001
		257,	//100000001
		257,	//100000001
		510,	//111111110
    };

    int K[] = {
		511,	//111111111
		40,	  //000101000
		68,	  //001000100
		130,	//010000010
		257,	//100000001
    };

    int L[] = {
		511,		//111111111
		1,	    //000000001
		1,	    //000000001
		1,	    //000000001
		1,	    //000000001
    };

    int M[] = {
		511,		//111111111
		128,		//010000000
		96,	    //001100000
		128,		//010000000
    511,		//111111111
    };

    int N[] = {
		511,		//111111111
		64,	    //001000000
		56,	    //000111000
		4,	    //000000100
		511,		//111111111
    };

    int O[] = {
		254,	//011111110
		257,	//100000001
		257,	//100000001
		257,	//100000001
		254,	//011111110
    };

    int P[] = {
		511,	//111111111
		272,	//100010000
		272,	//100010000
		272,	//100010000
		224,	//011100000
    };

    int Q[] = {
		252,	//011111100
		258,	//100000010
		258,	//100000010
		262,	//100000110
		255,	//011111111
    };

    int R[] = {
		511,	//111111111
		280,	//100011000
		276,	//100010100
		274,	//100010010
		225,	//011100001
    };

    int S[] = {
		226,	//011100010
		273,	//100010001
		273,	//100010001
		273,	//100010001
		142,	//010001110
    };

    int T[] = {
		256,	//100000000
		256,	//100000000
		511,	//111111111
		256,	//100000000
		256,	//100000000
    };

    int U[] = {
		510,	//111111110
		1,	 	//000000001
		1,	  //000000001
		1,	  //000000001
		510,	//111111110
    };

    int V[] = {
		508,	//111111100
		2,	  //000000010
		1,	  //000000001
		2,	  //000000010
		508,	//111111100
    };

    int W[] = {
		511,	//111111111
		6,	  //000000110
		24,	  //000011000
		6,	  //000000110
		511,	//111111111
    };

    int X[] = {
		257,	//100000001
		238,	//011101110
		16,	  //000010000
		238,	//011101110
		257,	//100000001
    };

    int Y[] = {
		496,	//111110000
		16,	  //000010000
		31,	  //000011111
		16,	  //000010000
		496,	//111110000
    };

    int Z[] = {
		263,	//100000111
		265,	//100001001
		273,	//100010001
		289,	//100100001
		449,	//111000001
    };

    
    int Exclamation_Mark[] = {
		0,	    //000000000
		509,    //111111101
		0,	    //000000000
    };

    int Heart[] = {
		224,	//011100000
		272,	//100010000
		264,	//100001000
		260,	//100000100
		131,	//010000011
		260,	//100000100
		264,	//100001000
		272,	//100010000
		224,	//011100000
		0,	  //000000000
    };

    int Smiley[] = {
		124,	//001111100
		130,	//010000010
		297,	//100101001
		261,	//100000101
		261,	//100000101
		297,	//100101001
		130,	//010000010
		124,	//001111100
    };

}


#endif