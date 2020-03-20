#ifndef STRUCTURES_H_   /* Include guard */
#define STRUCTURES_H_

const int MAX = 9999999;
const int MIN = -9999999;


typedef struct Neuron{
  float intv1, intv2;
  int dim, cls; // dimension, class
  int suc, ttl;
  bool on;
  struct Neuron * to;
}Neuron;


typedef struct String{ char * get; int alloc; int length; int i;} String;
typedef struct FloatArray{ float * get; int length; int alloc; int i;}FloatArray;
typedef struct FloatArray2{ FloatArray * get; int length; int alloc; int i;}FloatArray2;
typedef struct FloatArray3{ FloatArray2 * get; int length; int alloc; int i;} FloatArray3;
typedef struct FloatArray4{ FloatArray3 * get; int length; int alloc; int i;} FloatArray4;
typedef struct StringArray{ String * get; int length; int alloc; int i; }StringArray;

void StringConstr(  String * string, int alloc );
void StringParseFromFile( String * super, char * FILE_NAME );
void StringAppendString( String * string, char * c );
void StringAppendString2( String * string, char * c );
void StringAppendChar( String * string, char c );
void StringPrint( String * string );
void StringPrintTo( String * string, int to );
void StringReset( String * string );
int StringAutodetectDimensions2( char * c );
bool StringEqualsChars( String * str , char * chars );
void StringAppendFloatf( String * string, float flt, char * f );
int StringIndexOf( String * s , char * string );
void StringDoubleMoveDecimal( String * str, int places  );
void StringAppendString2( String * string, char * c );

void FloatArrayConstr( FloatArray * floats );
void FloatArrayPreventOverflow( FloatArray * floats );
void FloatArrayAdd( FloatArray * floats, float num  );
void FloatArrayPrint( FloatArray * floats );
void FloatArrayPrintfBr( FloatArray * floats , char * f, int everyi );
void FloatArrayPrintfBrTo( FloatArray * floats, char * f, int everyi, int to );
void FloatArrayPrintBr( FloatArray * floats , int everyi );
void FloatArrayReset( FloatArray * floatarray );
void FloatArrayPrintCompare( FloatArray * floats1, FloatArray * floats2 );
void FloatArrayPrintCompareMap( FloatArray * older, FloatArray * newer, FloatArray * indices );
void FloatArraySortAsc( FloatArray * floats );
void FloatArraySortDsc( FloatArray * floats );
void FloatArrayCopyFromTo( FloatArray * floatarray1 , FloatArray * floatarray2 );
void FloatArrayCopyToFrom( FloatArray * to, FloatArray * from );
void FloatArraySortMap2( FloatArray * map, FloatArray * unsorted , FloatArray * sorted, FloatArray * bufferFA );
void FloatArrayInstantiate( FloatArray * array, int number_of_indicies_desired, float value  );
void FloatArrayGetValueSet( FloatArray * indices , FloatArray * sorted );
void FloatArrayInstantiateAsc(FloatArray * array, int number_of_indicies_desired);
bool FloatArrayContains( FloatArray * floats, float value );
void FloatArrayShuffle( FloatArray * array );
void FloatArraySetIndicesByMap( FloatArray * array , FloatArray * map, FloatArray * buffer ); 
void FloatArrayInitialize( FloatArray * array, int number_of_indicies_desired );
void FloatArrayEnumerateAlphas(FloatArray * enumerations, StringArray * alpha_data, StringArray * alpha_set );
void FloatArrayFill( FloatArray * fill , float val );
float FloatArrayTotalFrom( FloatArray * floats, int from_col );
void FloatArrayRemoveIndex( FloatArray * floats, int index );
void FloatArrayGetUnique( FloatArray * unique_values, FloatArray * values );
void FloatArray2CopyToFrom2( FloatArray2 * to, FloatArray2 * from );
void FARmvCol( FloatArray * floats, int index );
void FACountValues( FloatArray * counts, FloatArray * data, FloatArray * values_to_count );

void FloatArray2Constr( FloatArray2 * floats );
void FloatArray2PreventOverflow( FloatArray2 * floats );
void FloatArray2Add( FloatArray2 * floats, FloatArray * num  );
void FloatArray2Reset( FloatArray2 * floats );
void FloatArray2AddEmpty( FloatArray2 * floats );
FloatArray *  FloatArray2GetEmpty( FloatArray2 * floats );


void FloatArray2PrintByRow( FloatArray2 * floats2d, int col_number );
void FloatArray2GetCol( FloatArray * column, FloatArray2 * floats2d, int col_number );
void FloatArray2CopyToFrom( FloatArray2 * to, FloatArray2 * from, FloatArray * bufferFA );
void FloatArray2ToColumns( FloatArray2 * values_in_columns, FloatArray * values , int number_of_columns, FloatArray * bufferFA  );
void FloatArray2GetIndicesByClass( FloatArray2 * indices, FloatArray * class_column, int number_of_classes, FloatArray * bufferFA );
void FloatArray2GetColumnMedians( FloatArray * medians , FloatArray2 * values_in_columns ,  FloatArray2 * bufferFATWO );
void FloatArray2FilterByClass( FloatArray2 * single_class, FloatArray2 * data, FloatArray2 * class_indices, int class_index, FloatArray * bufferFA );
void FloatArray2JoinDimension2ToFrom( FloatArray2 * FA2A , FloatArray2 * FA2B );
void FloatArray2SortSecondary( FloatArray2 * segments, FloatArray2 * double_sort, FloatArray * class_counts, int number_of_classes, int current_dimension , FloatArray * bufferFA );
void FloatArray2SetIndicesByMap( FloatArray2 * array , FloatArray * map, FloatArray * buffer );
void FloatArray2PrintRow( FloatArray2 * array , int row );
void FloatArray2Split2( FloatArray2 * values_in_columns_test, FloatArray2 *  values_in_columns, float test_ratio, int number_of_classes, FloatArray3 * buffer3  );
void FloatArray2Split( FloatArray2 * values_in_columns_test, FloatArray2 *  values_in_columns, float test_ratio, FloatArray * buffer  );
void FloatArray2InitializeD1( FloatArray2 * values, int number_of_top_dimensions, FloatArray * bufferFA );
void FloatArray2AddNew( FloatArray2 * floats, float num );
void FloatArray2AddTo( FloatArray2 * floats, int row, float num  );
void FloatArray2AddToLast( FloatArray2 * floats, float num  );
void FloatArray2Initialize2D1( FloatArray2 * values, int number_of_top_dimensions );
float FloatArray2GetRowTotal(FloatArray2 * segments, int row, int start_index);
void FloatArray2Print( FloatArray2 * values );
void FloatArray2COLRemoveRow( FloatArray2 * data_by_col, int index_to_remove );
void FA2Printfln( FloatArray2 * fa2, char * f );


void FloatArray3PreventOverflow( FloatArray3 * floats );
void FloatArray3Constr( FloatArray3 * floats );
void FloatArray3Add( FloatArray3 * floats, FloatArray2 * num  );
void FloatArray3Reset( FloatArray3 * floats );
void FloatArray3PrintTables( FloatArray3 * FA3 , int cols );
void FloatArray3InstantiateD1( FloatArray3 * values, int number_of_top_dimensions, FloatArray2 * bufferFA2, FloatArray * bufferFA1 );
void FloatArray3AddNew( FloatArray3 * floats);
FloatArray2 * FloatArray3Next( FloatArray3 * MEM );

void FloatArray4AddNew( FloatArray4 * floats);
  
void StringArrayReset( StringArray * stringArray );
void StringFree( String * string );
void StringArrayGetUnique( StringArray * S , StringArray * S2 );
void StringArrayPrintln( StringArray * s );
void StringArrayAdd( StringArray * s, char * string );
void StringArrayAddChar( StringArray * s, char chr );
void StringArrayConstr( StringArray * s );
void StringArraySeperateFloatsStrings( StringArray * data, FloatArray * floats, StringArray * classnames );
void StringArrayParseSuperstring( StringArray * strings , String * super_string, String * buffer );
void StringArrayAddEmpty( StringArray * sa );
int  StringArrayAutodetectDimensions_CountHeaderColumns( StringArray * strings );
int StringArrayContains( StringArray * s, char * string );


typedef struct LineArray{ float * x1, * y1, * x2, * y2; String * cls; int length, alloc, i, id;}LineArray;
void LineArrayReset( LineArray * linearray );
void LineArrayConstrN( LineArray * L, int length );
void LineArrayFree( LineArray * L );
void LineArrayAdd( LineArray * L , float x1, float y1, float x2, float y2, char * cls );
void LineArrayCopyFromTo( LineArray * linearray1 , LineArray * linearray2 );
void LineArrayPrint( LineArray * p );
void LineArrayPrintTo( LineArray * L , int length );
void LineArrayShiftY( LineArray * lines, float amt);
void LineArrayShiftX( LineArray * lines, float amt);


typedef struct PointArray{ float * x, * y; String * cls; int length; int alloc; int i; }PointArray;
void PointArrayConstr( PointArray * p, int length );
void PointArrayFree( PointArray * P );
void PointArrayAdd( PointArray * p , float x, float y, char * cls );
void PointArrayPrint( PointArray * p );
void PointArrayParseFloatArray(  PointArray * points , FloatArray * data, LineArray * grid, StringArray * classes, int DIMENSIONS );


void initCharArr( char * characters, int length );
int getIndex( int i, int j, int d );
int  length( char * chars );
int getIndexClass( int i, int j, int k, int c, int d );
bool isInt( char c ); 
bool isDouble( char c ); 
bool areDoubles( char * c );
bool isComma( char c );
float min( float one, float two );


// STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING 
// STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING 
// STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING // STRING 
void StringConstr( String * string, int alloc ){
  string->length = 0;
  string->alloc = alloc;
  string->i = 0;
  string->get = (char*) malloc( string->alloc *  sizeof(char) );
  initCharArr( string->get,  string->alloc );
}

void StringAppendChar( String * string, char c ){
  float tolerance = 1.5, growth = 2.0;
  bool reallocate = string->length * tolerance > string->alloc;
  if(  reallocate ){
    string->alloc *= growth;
    string->get = (char*) realloc( string->get , string->alloc *  sizeof(char) );
  } 
  string->get[ string->i ] = c;
  string->i++;
  string->length++;
}

void StringReset( String * string ){
  initCharArr( string->get , string->length );
  string->length = 0;
  string->i = 0;
}

void StringFree( String * string ){
  string->length = -1;
  string->alloc = -1;
  string->i = -1;
  free( string->get );
}




int StringAutodetectDimensions( char * c ){
  char x;
  int d;
  int d0 = -1;
  int i; 
  for( i = 0, d = 0; i < 300 ; i ++ ){ 
    x = c[ i ];
    if( isComma( x )){   d++;}
    
    if( isComma( x )  && !isDouble( c[ i + 1 ] ) && d0 == -1 ){ 
      d0 = d; 
      // printf("d0 = %i\n", d0);
    } 
    else
      if( isComma( x )  && !isDouble( c[ i + 1] ) && d0 != -1 ){ 
        //printf("\nd1 = (d-d0) = (%i-%i) = %i\n", d, d0, d-d0);
        return d-d0;
        
      }//return i - d0;}
      
      // printf("%c", x);
      
  }
  
  return -1;
}
int StringAutodetectDimensions2( char * c ){
  char x;
  int d;
  int d0 = -1;
  int i; 
  for( i = 0, d = 0; i < 300 ; i ++ ){ 
    x = c[ i ];
    if( isComma( x )){   d++;}
    
    if( isComma( x )  && !isDouble( c[ i + 1 ] ) && d0 == -1 ){ 
      d0 = d; 
      // printf("d0 = %i\n", d0);
    } 
    else
      if( isComma( x )  && !isDouble( c[ i + 1] ) && d0 != -1 ){ 
        //printf("\nd1 = (d-d0) = (%i-%i) = %i\n", d, d0, d-d0);
        return d-d0;
        
      }//return i - d0;}
      
      // printf("%c", x);
      
  }
  
  return -1;
}
void StringPrint( String * string ){
  int i;
  printf("(L) = %i\n", string->length ); 
  for( i = 0; i < string->length; i++ ){
    printf("%c ",  string->get[i] );
  }
  printf("\n");
}

void StringArrayAddCharNew( StringArray * sa , char chr ){
    StringArrayAddChar( sa, chr ); 
}
void StringArrayRemoveIndex( StringArray * floats, int index ){
  int L1 = floats -> length;
  bool remove_last = index == L1 - 1;
  int i;
  if( !remove_last ){
    for( i = index ; i < L1 - 1; i++ ){
      floats -> get[i] = floats -> get[i + 1];
    }
  }
  floats->length--;
}


void StringArrayRemoveIndices( StringArray * floats, FloatArray * indices ){
  int i;
  int L1 = indices -> length;
  int index;
  for(i = L1 -1 ; i >= 0; i--  ){
    index = indices ->get[i];
    StringArrayRemoveIndex( floats, index ); 
  }
}

void StringArrayUnscientificNotation( StringArray * data_notype ){
  // Changes scientific notation into decimal format.
  
  bool VERBOSE = false;
  String Buf; String * buf = &Buf; StringConstr( buf, 20 ); 
  
  int noDecimalBeforeE;
  float num;
  int i , j, index, dec, jump;
  bool isNeg, isNum;
  String * str;
  if(VERBOSE)printf("L2 = (%i)\n", length((char*)"e") );
  for( i = 0; i < data_notype->length; i++ ){
    str = &data_notype -> get[i] ;
    index = StringIndexOf( str , (char*)"e");
    
    if( index != -1 ){
      // 2.337e-005 (has decimal) move the decimal point right 5 places. retuns 0.00002337
      // 3e-005	(no decimal) (fails to) move the decimal point right 5 places. retuns 0.00002337
      noDecimalBeforeE = StringIndexOf( str , (char*)".");
      if(VERBOSE)printf("found match: %s\t", str->get  );
      if(VERBOSE)printf("\tnum: ");
      StringReset( buf );
      for( j =0 ; j < index; j++ ){ StringAppendChar( buf, str->get[j] );}// str->get[j];}//printf("%c", );
      isNum = areDoubles( buf->get );
      if(!isNum) continue; // if string (left of 'e') is not a number containg 'e' then continue
      
      num = atof( buf->get );
      if(VERBOSE)printf( "%f", num );
      isNeg = str->get[ index + 1 ] == '-';
      jump = isNeg ? 2 : 1; // if there is a negative sign jump two indices;
      
      if(VERBOSE)printf("\tdec: ");
      StringReset( buf );
      for( j =index + jump ; j < str->length; j++ )  StringAppendChar( buf, str->get[j] );
      dec = atof( buf->get ) * (isNeg ? -1 : 1);
      if(VERBOSE)printf( "%i\t", dec );
      
      
      StringReset( buf );
      for( j =0 ; j < index; j++ ){ StringAppendChar( buf, str->get[j] );}
      if( noDecimalBeforeE == -1 ) StringAppendString2( buf, (char*)".00" );
      if(VERBOSE)printf( "(%s ->\t", buf->get );
      StringDoubleMoveDecimal(buf, dec );
      if(VERBOSE)printf( "%s)", buf->get );
      StringReset( &data_notype -> get[i] );
      StringAppendString2( &data_notype -> get[i], buf->get );
      if(VERBOSE)printf("\n");
    } 
    
   
    
    
    
    
  }
  
  StringFree( buf );
}
void StringDoubleMoveDecimal( String * str, int places  ){
    int VERBOSE = false;
    int VERBOSE1 = false;
    int i;
    int index = StringIndexOf( str, (char*) "." );
    int plus;
    int extra_points;
    bool move_right = places < 0;
    bool move_left = places > 0;
    if(VERBOSE || VERBOSE1 )printf("before: %s\n", str->get);
    if( index != -1 ){
        if( move_right ){
            places *= -1;
            plus = 0;
            
            for( i = 0 ; i < places; i++ ) StringAppendChar( str, '0' );
            
            for( i = str->length - 1 - places; i >= 0 ; i-- ){
              if( str->get[i] == '.' ){ plus = 1; continue;} 
              str->get[ i + places + plus] = str->get[i];
            }  
            for( i = 0; i < places ; i++ ){
              if( str->get[i] == '.' ) continue;
              str->get[ i ] = '0';
            }  
            
            
        } else 
        if( move_left ){
            
            if(VERBOSE)printf("index: %i\n", index);
            
            extra_points = places - (str->length - index - 1);
            for( i = 0 ; i < extra_points; i++ ) StringAppendChar( str, '0' );
            if(VERBOSE)printf("str-len: %i\n", str->length - 1);
            for( i = index ; i < str->length - 1; i++ ){
              str->get[i] = str->get[i + 1];
              if(VERBOSE)printf("set: %c to %c\n", str->get[i], str->get[i+1]);
            } 
            
            
        }
    }
    if(VERBOSE || VERBOSE1 ) printf("after: %s\n", str->get);
}

void StrDblMoveDecimal( String * str, int places ){
    StringDoubleMoveDecimal( str, places ); 
}

void  StringUnscientificNotation(){
  
}

int StrGetColMaxCharLengthCSV( String * csv_row, int col ){
  int result = -1;
  int i, L1 = csv_row->length, f = L1 - 1;
  int c = 0;
  char chr;
  int COMMA = (int) ',';
  int count = 0;
  for( i = 0; i < L1; i++ ){
    chr = csv_row ->get[i];
    if((int)chr == COMMA || i == f ){ 
      if( c++ != col ){
        count = 0;
        continue;
      } 
      if( count > result ) result = count; 
      count = 0; 
      continue;
    }
    count++;
  }
  return result;
}


int SAGetColMaxCharLengthCSV( StringArray * sa, int col ){
  int result = -1;
  int i, L1 = sa -> length;
  int val;
  String * str;
  for( i = 0 ; i < L1; i++ ){
    str = &sa->get[i];
    val = StrGetColMaxCharLengthCSV( str, col  ); 
    if( val > result ) result = val;
  }
  return result;
}


void StringArrayAddCharToLast( StringArray * sa , char chr ){
  int f = sa->length - 1;
  String * str = &sa->get[f];
  StringAppendChar( str , chr ); 
}


void StringArraySplitByChar( StringArray * sa, char * str , char chr ){
  int i, j, L1 = length(str);
  char c;
  int index1 = 0, index2;
  //printf("CHAR: %s\n", str); 
  for(i = 0 ; i < L1; i++ ){
    c = str[i];
    if( c == chr || i == L1 - 1){
      index2 = i;
      if(i == L1 - 1) index2++;
      //printf("from index %i to %i\t", index1, index2); 
      StringArrayAddEmpty( sa );
      for(j = index1; j < index2; j++ ){
        //printf("%c", str[j]);
        StringArrayAddCharToLast( sa, str[j] );
      }
      //printf("\n");
      index1 = i + 1;
    }
  }
  //StringArrayPrintln( sa ); 
}


void StringArraySplitBetweenChars( StringArray * sa, char * str, char char_1, char char_2 ){
  // Example - get all strings between char '(' and char ')'
  // Example - get all strings enclosed in parenthesis
  // only at the first depth; parenthesis within parenthesis would 
  // have to be grabbed in a successive round
  int i, j, L1 = length(str);
  char c;
  char var = 'X';
  int depth = 0;
  char c1 = char_1, c2 = char_2;
  int index1, index2;
  printf("parsing: %s\n", str ); 
  for(i = 0 ; i < L1; i++ ){
    c = str[i];
    if( c == c1 ) depth++;
    if( c == c2 ) depth--;
    if( c == c1 && depth == 1) index1 = i;
    if(( c == c2 && depth == 0) || i == L1 - 1){
      index1++;
      index2 = i;
      printf("from index %i to %i\n", index1, index2 - 1); 
      StringArrayAddEmpty( sa );
      for(j = index1; j < index2; j++ ){
        StringArrayAddCharToLast( sa, str[j] );
      }
    }
  }
  //StringArrayPrintln( sa ); 
}
void StringArrayAddEmpty( StringArray * sa ){
  char chr = ' ';
  StringArrayAddCharNew( sa, chr );
  StringReset( &sa ->get[ sa ->length - 1] );
}

void StrExport( String * string, char * FULL_FILEPATH ){
  FILE *  save = fopen ( FULL_FILEPATH , "w" );
  int i;
  for( i = 0 ; i < string->length; i++ ){
    fprintf (save, "%c",  string->get[i] );
  }
  fclose (save);
}

void StringPrintf( String * string , char * f ){
  int i;
  //printf("(L) = %i\n", string->length ); 
  for( i = 0; i < string->length; i++ ){
    printf( f ,  string->get[i] );
  }
  printf("\n");
}
void StringPrintTo( String * string, int to ){
  int i;
  for( i = 0 ; i < to; i++ ){
    printf("%c", string->get[i] );
  }
} 

void StringAppendString( String * string, char * c ){
  int i, f = length(c) - 1; 
  for( i = 0 ; i < f + 1; i++ ){
    StringAppendChar( string , c[i] );
  }
}
void StringAppendTab( String * string, int tabs ){
  int i;
  for( i = 0 ; i < tabs; i++ ){
    StringAppendChar( string , '\t' );
  }
}
void StringAppendStringTab( String * string, char * c, int tabs  ){
  int i, f = length(c) - 1; 
  for( i = 0 ; i < tabs; i++ ){
    StringAppendChar( string , '\t' );
  }
  for( i = 0 ; i < f + 1; i++ ){
    StringAppendChar( string , c[i] );
  }
}
void StringAppendStringTabLn( String * string, char * c, int tabs ){
    StringAppendStringTab( string, c, tabs );
    StringAppendChar( string , '\n' );
}

void StringAppendString2( String * string, char * c ){
  int i, f = length(c) - 1; 
  for( i = 0 ; i < f + 1; i++ ){
    StringAppendChar( string , c[i] );
  }
}

void StrPrint( String * str ){
  int i, L = str -> length; 
  for(i = 0 ; i < L; i ++ ){
    printf( "%c", str->get[i] ); 
  }
}

void StringParseFromFileDelimeter( String * super, char delimiterA, char delimiterB,  char * FILE_NAME){
  FILE *ptr_file = fopen( FILE_NAME , "r" );
  int alloc = 100;
  char buf[alloc], x;
  //int limiter = 0; printf("\n"); 
  int f;
  char prev;
  int i0 = 0, i1 = 0;
  while( !feof(ptr_file) ){
    //if( limiter++ > 20 ){ break; }
    initCharArr( buf, alloc );
    fgets( buf, alloc, ptr_file);
    int i; for( i = 0; i < alloc; i++){
      prev = x;
      x = buf[i];
      if( x == '\n' ){ 
        StringAppendChar( super , delimiterB);
        //printf("%c", ',' );
        continue;
      }
      
      if( x == '\t' ){  StringAppendChar( super , delimiterB); continue; }
      if( x == delimiterA ){ StringAppendChar( super , delimiterB); continue; }
      if( x == '\0' ){ continue; }
      
      
      
      StringAppendChar( super , x );
      
    }
    
  }
  fclose( ptr_file );
  
};
void StringParseFromFile( String * super, char * FILE_NAME){
  FILE *ptr_file = fopen( FILE_NAME , "r" );
  int alloc = 100;
  char buf[alloc], x;
  //int limiter = 0; printf("\n"); 
  int f;
  char prev;
  int i0 = 0, i1 = 0;
  while( !feof(ptr_file) ){
    //if( limiter++ > 20 ){ break; }
    initCharArr( buf, alloc );
    fgets( buf, alloc, ptr_file);
    int i; for( i = 0; i < alloc; i++){
      prev = x;
      x = buf[i];
      if( x == '\n' ){ 
        StringAppendChar( super , ',');
        //printf("%c", ',' );
        continue;
      }
      
      if( x == '\t' ){  StringAppendChar( super , ','); continue; }
      if( x == ' ' ){ continue; }
      if( x == '\0' ){ continue; }
      
      
      
      StringAppendChar( super , x );
      
    }
    
  }
  fclose( ptr_file );
  
};




////////////////////////// STRING ARRAY //////////////////////////

void StringArrayReset( StringArray * stringArray ){
  int i = 0;
  for( i = 0 ; i < stringArray->length; i++ ){
    StringReset( &stringArray->get[i] ); 
  }
  stringArray->length = 0;
  stringArray->i = 0;
}

bool CharContainsChar2( char * s , char * string, int length ){
  int  i;
  char c1, c2;
  for( i = 0 ; i < length; i++ ){
    c1 = s[i];
    c2 = string[i];
    
    
    if( c1 == '\0' || c2 == '\0' ) return true;
    if( c1 != c2 ) return false;
  }
  return true;
}

bool CharContainsChar( char * s , char * string ){
  int  i;
  char c1, c2;
  int len = length( string );
  for( i = 0 ; i < len; i++ ){
    c1 = s[i];
    c2 = string[i];
    
    
    if( c1 == '\0' || c2 == '\0' ) return true;
    if( c1 != c2 ) return false;
  }
  return true;
}

bool StringContainsChars( String * s , char * string ){
  int  i;
  char c1, c2;
  for( i = 0 ; i < s->length; i++ ){
    c1 = s->get[i];
    c2 = string[i];
    if( c1 == '\0' || c2 == '\0' ) return true;
    if( c1 != c2 ) return false;
  }
  return true;
}





int StringIndexOf( String * s , char * string ){
  // the ContainsChars only checks if the starting characters are the same. 
  // This match can be anywhere in the string
  int  i, j, L, L2 = length( string );
  char c1, c2;
  char initial = string[0];
  for( i = 0 ; i < s->length; i++ ){
    c1 = s->get[i];
    c2 = initial;
    if( c1 == '\0' || c2 == '\0' ) return -1;
    if( c1 == c2 ){
      //
      for( j = 0 ; j < L2; j++ ){
        c1 = s->get[i + j];
        c2 = string[j ];
        if( c1 != c2 ) return -1;
      }
      return i;
    }
  }
  return -1;
}
bool StringEqualsChars( String * str , char * chars ){
  
  int i;
  char a, b;
  bool eql;
  for( i =0 ; i < str->length; i++ ){
    a = str ->get[i];
    b = chars[i];
    eql = a == b;
    
    if(!eql) return false;
    
    
  }
  return true;
  
}



int StringArrayAutodetectDimensions_CountHeaderColumns( StringArray * strings ){
  
  //Counts number of consequitive colums that start with a non-numeric character ( i.e. not 0->1, or a decimal place)
  //For example, if the first ten columns of row one all start with alpha characters, the count would be ten. 
  
  int count = 0;
  int i , j;
  for( i = 0 ; i < strings->length; i++ ){
    bool df = isDouble( strings->get[i].get[0] );
    if( !df ){ count++; }else{ break;}
    //printf("%c ", df ? 'T' : 'F'); 
  }
  return count;
}


void StringArraySeperateFloatsStrings2(  FloatArray * floats, StringArray * classnames, StringArray * data ){
  int i;
  char x;
  for(i = 0 ; i < data->length; i++  ){
    x = data->get[i].get[0];
    if( isDouble(x) ){ 
      //printf("made this: %s\n", data->get[i].get ); 
      FloatArrayAdd( floats , (float) atof( data->get[i].get ) ); 
      
    } else{
      
      StringArrayAdd( classnames, data->get[i].get );
      
    }
  }
  
}

void StringArraySeperateFloatsStrings( StringArray * data, FloatArray * floats, StringArray * classnames ){
  int i;
  char x;
  for(i = 0 ; i < data->length; i++  ){
    x = data->get[i].get[0];
    if( isDouble(x) ){ 
      //printf("made this: %s\n", data->get[i].get ); 
      FloatArrayAdd( floats , (float) atof( data->get[i].get ) ); 
      
    } else{
      
      StringArrayAdd( classnames, data->get[i].get );
      
    }
  }
  
}

void StringArrayConstr( StringArray * s ){
  s->length = 0;
  s->alloc = 50;
  s->i = 0;
  s->get = (String*) malloc( s->alloc *  sizeof(String) );
}

void StringArrayAdd( StringArray * s, char * string ){
  int CHARS = 100;
  float tolerance = 1.5, growth = 2.0;
  bool reallocate = s->length * tolerance > s->alloc;
  if(  reallocate ){
    //printf("realloc: %f \n" , (float)s->length * tolerance ); 
    //printf("%i< alloc \n" , s->alloc ); 
    s->alloc *= growth;
    s->get = (String*) realloc( s->get , s->alloc *  sizeof(String) );
  } 
  StringConstr( &s->get[s->length] , CHARS );
  StringAppendString( &s->get[s->length] , string );
  s->i++;
  s->length++;
}
void StringArrayAddChar( StringArray * s, char chr ){
  int CHARS = 100;
  float tolerance = 1.5, growth = 2.0;
  bool reallocate = s->length * tolerance > s->alloc;
  if(  reallocate ){
    //printf("realloc: %f \n" , (float)s->length * tolerance ); 
    //printf("%i< alloc \n" , s->alloc ); 
    s->alloc *= growth;
    s->get = (String*) realloc( s->get , s->alloc *  sizeof(String) );
  } 
  StringConstr( &s->get[s->length] , CHARS );
  StringAppendChar( &s->get[s->length] , chr );
  s->i++;
  s->length++;
}
int StringArrayContains( StringArray * s, char * string ){
  
  int i, j, str_len1, str_len2;
  char c1, c2;
  bool fnd, eql, end;
  for( i = 0 ; i < s->length; i++){
    fnd = true;
    for( j = 0; s->get[i].length; j++){
      c1 = s->get[i].get[j];
      c2 = string[j];
      end = c2 == '\0';
      if( end ) break;
      eql = c1 == c2;
      if(!eql ){ fnd = false; break;}
    }
    //if( fnd ){ printf("found (%s) at index: %i\n", s->get[i].get, i ); }
    if( fnd ) return i;
  }
  return -1;
}
void StringArrayGetUnique( StringArray * S , StringArray * S2 ){
  int i;
  bool exists;
  char * classname;
  char * str;
  for( i = 0 ; i < S2->length; i++ ){
    
    str =  S2->get[i].get;
    //printf( "%s ", str  ); 
    exists = StringArrayContains( S, str ) != -1;
    
    if ( !exists ){  StringArrayAdd( S , str );  }
  }
}
void StringArrayPrintln( StringArray * s ){
  int i;
  for( i = 0 ; i < s->length; i++){
    printf("[%i] %s (%i)\n", i , s->get[i].get, length(s->get[i].get) );
  }
};

void StringArrayParseSuperstring( StringArray * strings , String * super_string, String * buffer ){
  char x, ASCII_CHARACTER_CARRIAGE_RETURN = (char) 13; // how did this end up in the text file?
  StringReset( buffer );
  int i; 
  for( i = 0; i < super_string->length; i++ ){
    x = super_string->get[i];
    if( x == ASCII_CHARACTER_CARRIAGE_RETURN ) continue;
    if( isComma(x) ){
      //printf("adding: %s(%i)\n" , buffer->get, strings->length); 
      StringArrayAdd( strings , buffer->get ); 
      StringReset( buffer );
      continue;
    }
    
    StringAppendChar( buffer , x );
  }
  if( length(buffer->get) > 0 ) StringArrayAdd( strings , buffer->get ); 
  //StringArrayPrintln( strings ); 
}

void StringArrayCutSubarray( StringArray * cut, StringArray * original_array, int r1, int r2, int c1, int c2, int columns ){
  int i, j, indx;
  for(i = r1; i < r2; i++){
    for( j = c1; j < c2; j++){
      indx = (i * columns) + j;
      StringArrayAdd( cut,  original_array->get[indx].get ); 
    }
  }
  // could make this dynamic
}


////////////////////////// FLOAT ARRAY //////////////////////////
void FloatArrayAdd( FloatArray * floats, float num  ){
  int index = (floats->length);
  floats->length++;
  floats->get[ index ] = num;
  FloatArrayPreventOverflow( floats );
}


void FloatArrayFree( FloatArray * floats ){
  floats->length = -1;
  floats->alloc = -1;
  floats->i = -1;
  free( floats->get );
}

float FloatTotalFromTo( FloatArray * values , int from, int to ){
  int result = 0.0f;
  int L1 = to + 1;
  if( from < 0 || L1 > values -> length )  return result;
  int ttl = 0.0f;
  int i , j;
  for(i = from ; i < L1; i++ ){
    ttl += values ->get[i];
  }  
  result = ttl;
  return result;
}
float FloatArrayGetRatioColFromTo( FloatArray * floats, int from_index, int to_index, int col ){
  bool VERBOSE = false;
  float result, ttl, val;
  int L1 = to_index != -1 ? to_index + 1 : floats ->length;
  int i;
  val = floats ->get[ col ];
  ttl = FloatTotalFromTo( floats, from_index, to_index ); 
  if(VERBOSE)printf("\t\tttl = %f\t val = %f\n", ttl, val); 
  result = (val == 0 || ttl == 0 ) ? 0.0f : val / ttl;
  return result;
}


void FloatArrayPrint( FloatArray * floats ){
  printf("--------------------------\n");
  int i; for( i = 0 ; i < floats->length; i++ ){
    printf("[%i] %f\n", i, floats->get[i] );  
  }
}

void FAMapApply( FloatArray * remapped, FloatArray * data, FloatArray * indices_map ){
  int L = indices_map ->length;
  float val;
  int index;
  for( int i = 0; i < L; i++ ){
    index = indices_map->get[i];
    val = data -> get[ index ];
    FloatArrayAdd( remapped, val ); 
  }
}
void FAGetColAtIndices( FloatArray * col, FloatArray2 * data, FloatArray * row_indices, int col_k){
  int i, L = row_indices->length;
  int index;
  float val;
  for( i = 0 ; i < L; i++ ){
      index = row_indices->get[i];
      val = data->get[ index ].get[col_k];
      FloatArrayAdd( col, val );  
  }
}
void FloatArrayEnumerateAlphas(FloatArray * enumerations, StringArray * alpha_data, StringArray * alpha_set ){
  // ASSUMES ONLY ONE COLUMN AT A TIME
  int i, j;
  char * chars;
  int match;
  bool VERBOSE = false;
  String * string;
  for( i = 0 ; i < alpha_data->length; i++  ){
    string = &alpha_data->get[i];
    for( j = 0 ; j < alpha_set->length; j++ ){
      chars = alpha_set->get[j].get;
      match = StringEqualsChars( string , chars ) ? j : -1;
      if( match != -1 ) break;
    }
    if(VERBOSE)printf("match!(%s)(%s) <- (%i)\n", string->get, chars, match); 
    FloatArrayAdd( enumerations , match );
  }
}

void FAPrintfBr( FloatArray * floats, char * f, int everyi ){
  int i; 
  int cnt = 0;
  bool no_line_skip = everyi == -1 || everyi == 0;
  if( no_line_skip ){ everyi = MAX; }
  for( i = 0 ; i < floats->length; i++ ){
    printf( f ,floats->get[i] );  
    if( cnt++ >= everyi - 1){ printf("\n"); cnt = 0; }
  }
  if(!no_line_skip)printf("\n");
}


  
void FloatArrayAddIndex( FloatArray * to, FloatArray * from, FloatArray * indices ){
  int index;
  float val;
  for(int i = 0 ; i < indices->length; i++ ){
      index   = indices -> get[i];
      val     = from->get[index];
      FloatArrayAdd( to , val );
  }
}

void FloatArray2AddIndex( FloatArray2 * to, FloatArray2 * from, FloatArray * indices ){
  int index;
  float val;
  FloatArray * fa1;
  for(int i = 0 ; i < indices->length; i++ ){
    index   = indices -> get[i];
    fa1 = &from -> get[ index ];
    FloatArray2Add( to , fa1 );
  }
}

FloatArray2* FloatArray2AddIndex3( FloatArray2 * from, FloatArray * indices, FloatArray3 * bufferFA3 ){
  FloatArray2 * to = FloatArray3Next( bufferFA3 );
  int index;
  float val;
  FloatArray * fa1;
  for(int i = 0 ; i < indices->length; i++ ){
    index   = indices -> get[i];
    fa1 = &from -> get[ index ];
    FloatArray2Add( to , fa1 );
  }
  return to;
}

void FAPrintfIndices( FloatArray * floats, char * f, FloatArray * indices ){
  int i, index;
  int cnt = 0;
  float val;
  int everyi = -1;
  bool no_line_skip = everyi == -1 || everyi == 0;
  if( no_line_skip ){ everyi = MAX; }
  for( i = 0 ; i < indices->length; i++ ){
    index = indices->get[i];
    val = floats->get[index];
    printf( f , val );  
    if( cnt++ >= everyi - 1){ printf("\n"); cnt = 0; }
  }
  if(!no_line_skip)printf("\n");
}
 
void PrintSection( char c, int times ){
  int i;
  for( i = 0 ; i < times; i++ ){
    printf("%c", c);
    
  }
  printf("\n");
  
} 
void FAPrintf( FloatArray * floats, char * f ){
    FAPrintfBr( floats, f, -1 );
}

void FAPrintfTo( FloatArray * floats, char * f, int TO ){
  int i; 
  int cnt = 0;
  if(TO > floats->length) TO = floats->length;
  for( i = 0 ; i < TO; i++ ){
    printf( f ,floats->get[i] );  
  }
}

void FAPrintflnTo( FloatArray * floats, char * f, int TO ){
  FAPrintfTo(floats, f, TO ); 
  printf("\n");
}
void FAPrintfSub( FloatArray * floats, char * f, int from, int toL ){
  int i; 
  int cnt = 0;
  int everyi = -1;
  bool no_line_skip = everyi == -1 || everyi == 0;
  if( no_line_skip ){ everyi = MAX; }
  for( i = from ; i < toL; i++ ){
    printf( f ,floats->get[i] );  
    if( cnt++ >= everyi - 1){ printf("\n"); cnt = 0; }
  }
  if(!no_line_skip)printf("\n");
}

void FAPrintfln( FloatArray * floats, char * f ){
    FAPrintf( floats, f ); 
    printf("\n");
}

void FAPrintflnSub( FloatArray * floats, char * f, int from, int toL ){
  FAPrintfSub(floats, f, from, toL ); 
  printf("\n");
}
void FloatArrayPrintfBr( FloatArray * floats, char * f, int everyi ){
    FAPrintfBr( floats, f, everyi );
}

void FAEnumerate( FloatArray * data ){
  FloatArray FA; FloatArray * fa = &FA; FloatArrayConstr( fa );
  FloatArrayGetUnique( fa, data );
  FloatArraySortAsc( fa );
  int i, j, L = data->length, L2 = fa->length;
  float val1, val2;
  bool found;
  for(i = 0 ; i < L ; i++ ){
      val1 = data->get[i];
      for(j = 0 ; j < L2; j++ ){
          val2 = fa->get[j];
          found = val1 == val2;
          if( found ){
              data->get[i] = j;
              break;
          }
      }
  }
  FloatArrayFree( fa );
}



float FloatArrayGetMaxFrom( FloatArray * array, int from_index ){
  float max = MIN;
  int i;
  int L = array -> length;
  float val;
  for(i = from_index; i < L; i++ ){
    val = array ->get[i];
    if( val > max ){
      max = val;
    }
  }
  return max;
}
float FloatArrayGetMax( FloatArray * array ){
  float max = MIN;
  int i;
  int L = array -> length;
  float val;
  for(i = 0; i < L; i++ ){
    val = array ->get[i];
    if( val > max ){
      max = val;
    }
  }
  return max;
}

int FloatArrayGetIndexOfMax( FloatArray * array ){
  float max = MIN, index;
  int i;
  int L = array -> length;
  float val;
  for(i = 0; i < L; i++ ){
    val = array ->get[i];
    if( val > max ){
      max = val;
      index = i;
    }
  }
  return index;
}


int FloatArrayGetIndexOfMin( FloatArray * array ){
  float min = MAX, index;
  int i;
  int L = array -> length;
  float val;
  for(i = 0; i < L; i++ ){
    val = array ->get[i];
    if( val < min ){
      min = val;
      index = i;
    }
  }
  return index;
}


void FloatArray2GetIndexOfMax( FloatArray * indices_of_max_col, FloatArray2 * array2 ){
    // gets the index of the column with the max value, for every FA2 index
    int i, j;
    int L1 = array2 -> length;
    int L2 = array2 -> get[0].length;
    int max;
    FloatArray * array;
    for( i = 0 ; i < L1; i++ ){
        array = &array2->get[i];
        max = FloatArrayGetIndexOfMax( array );
        FloatArrayAdd( indices_of_max_col, max ); 
    }
}


float FloatArrayGetMin( FloatArray * array ){
  float min = MAX;
  int i;
  int L = array -> length;
  float val;
  for(i = 0; i < L; i++ ){
    val = array ->get[i];
    if( val < min ){
      min = val;
    }
  }
  return min;
}
void FloatArrayPrintfBrTo( FloatArray * floats, char * f, int everyi, int to ){
  int i; 
  int cnt = 0;
  int len = min(to, floats->length);
  for( i = 0 ; i < len; i++ ){
    printf( f ,floats->get[i] );  
    if( cnt++ >= everyi - 1){ printf("\n"); cnt = 0; }
  }
}
void FloatArrayPrintBr( FloatArray * floats, int everyi ){
  printf("--------------------------\n");
  int i; 
  int cnt = 0;
  for( i = 0 ; i < floats->length; i++ ){
    printf("%f\t",floats->get[i] );  
    if( cnt++ >= everyi - 1){ printf("\n"); cnt = 0; }
  }
}

void FloatArrayPrintCompare( FloatArray * floats1, FloatArray * floats2 ){
  printf("--------------------------\n");
  int i; 
  bool eql;
  for( i = 0 ; i < floats1->length; i++ ){
    eql = floats1->get[i] == floats1->get[i];
    printf("%f == %f : %s\n",floats1->get[i] , floats2->get[i] , eql ? "T" : "F" );  
    
  }
}

void FloatArrayPrintCompareMap( FloatArray * older, FloatArray * newer, FloatArray * indices ){
  printf("--------------------------\n");
  int i, map;
  bool eql;
  float val1, val2;
  for( i = 0 ; i < older->length; i++ ){
    map = indices->get[ i ];
    val1 = older->get[ i ];
    val2 = newer->get[ map ];
    eql = val1 == val2;
    printf("%f == %f : %s\t( %i -> %i )\n",val1 , val2 , eql ? "T" : "F", i, map );  
  }
} 
void FloatArrayCopyFromToSubset( FloatArray * floatarray1 , FloatArray * floatarray2, int index0, int length ){
  int i;
  for( i = index0 ; i < index0 + length; i++ ){
    FloatArrayAdd( floatarray2 , floatarray1->get[i] ); 
  }
}

void FloatArrayCopyToFrom( FloatArray * to, FloatArray * from ){
  int i;
  int L1 = from->length;
  float val;
  for( i = 0 ; i < L1; i++ ){
      val = from->get[i];
      FloatArrayAdd( to, val );
  }
}

void FloatArrayReset( FloatArray * floatarray ){
  floatarray->length = 0;
  floatarray->i = 0;
}

void FloatArrayPreventOverflow( FloatArray * floats ){
  int INITIAL_AMT = 25;
  float GROWTH = 2.0, THRESHOLD = 1.5;
  if( floats->alloc == 0 ){
    floats->alloc = INITIAL_AMT;
    floats->get = (float*) malloc( floats->alloc * sizeof(float) );
  } else {
    float usage = floats->length * THRESHOLD;
    if( usage >= ( floats->alloc  ) ){
      floats->alloc *= GROWTH;
      floats->get = (float*) realloc( floats->get, floats->alloc * sizeof(float) );
    }
  }
}
void FloatArrayConstr( FloatArray * floats ){
  floats->length = 0;
  floats->alloc = 0;
  floats->i = 0;
  FloatArrayPreventOverflow( floats );
} 

void FloatArrayCopyFromTo( FloatArray * floatarray1 , FloatArray * floatarray2 ){
  int i;
  for( i = 0 ; i < floatarray1->length; i++ ){
    FloatArrayAdd( floatarray2 , floatarray1->get[i] ); 
  }
}

void FloatArraySetIndicesByMap( FloatArray * array , FloatArray * map, FloatArray * buffer ){
  int i, j, index;
  int L = map->length;
  bool VERBOSE = false;
  FloatArrayInitialize( array , map->length );
  FloatArrayInitialize( buffer , map->length );
  for( i = 0 ; i < L ; i++ ){
      index = map->get[i];
      buffer->get[ index ] = array->get[ i ];
      if(VERBOSE)printf("%i -> %i\n", index, i );
  }
  FloatArrayReset( array );
  FloatArrayCopyFromTo( buffer, array );
}


void FloatArray2Split( FloatArray2 * values_in_columns_test, FloatArray2 *  values_in_columns, float test_ratio, FloatArray * buffer  ){
  bool VERBOSE = false;
  int train_values_n = values_in_columns->get[0].length;
  int test_values_n = (train_values_n * test_ratio);
  train_values_n -= test_values_n;
  if(VERBOSE)printf("total: %i\t test: %i\t train: %i\n", values_in_columns->get[0].length, train_values_n, test_values_n); 
  
  
  // FloatArrayReset( buffer ); 
  int i, j;
  int cols = values_in_columns -> length;
  int index1, index2;
  FloatArrayReset( buffer ); 
  FloatArray2InitializeD1( values_in_columns_test, cols , buffer );
  index1 = train_values_n;
  index2 = train_values_n + test_values_n - 1;
  
  for(i = 0; i < cols; i++ ){
    for(j = index1; j < index2 + 1; j++ ){
      FloatArrayAdd( &values_in_columns_test->get[i],  values_in_columns->get[i].get[j] );
    }
    values_in_columns->get[i].length = index1;
  }
  if(VERBOSE)printf("%i \n", values_in_columns_test ->length );
  if(VERBOSE)printf("starting from index %i to index %i\n", train_values_n, train_values_n + test_values_n - 1);
  if(VERBOSE)printf("indices train: %i\t indices test: %i\n", values_in_columns->get[0].length, values_in_columns_test->get[0].length ); 
  if(VERBOSE)printf("----------------------------------------\n"); 
  
  
  
  
  
}


FloatArray3 * FloatArray4Next( FloatArray4 * MEM ){
  FloatArray4AddNew( MEM );
  FloatArray3 * floats = &MEM->get[ MEM -> length - 1];
  FloatArray3Reset( floats );
  return floats;
}
FloatArray2 * FloatArray3Next( FloatArray3 * MEM ){
  FloatArray3AddNew( MEM );
  FloatArray2 * floats = &MEM->get[ MEM -> length - 1];
  FloatArray2Reset( floats );
  return floats;
}
FloatArray * FloatArray2Next( FloatArray2 * MEM ){
  FloatArray2AddNew( MEM , 0.0f );
  FloatArray * floats = &MEM->get[ MEM -> length - 1];
  FloatArrayReset( floats );
  return floats;
}



void FloatArray2RowErase_COLUMN(FloatArray2 * array_from, int from_row, float clear_value ){
  // C - column format, top dimension is colums
  
  int i , j;
  bool VERBOSE = true;
  float val;
  for( i = 0 ; i < array_from -> length; i++ ){
    array_from ->get[i].get[ from_row ] = clear_value;
  
  }  
  
  
  
}


void FloatArray2CopyRowFromTo_COLUMN(FloatArray2 * array_from, FloatArray2 * array_to, int from_row ){
  // C - column format, top dimension is colums
  
  int i , j;
  bool VERBOSE = true;
  float val;
  
  
  for( i = 0 ; i < array_from -> length; i++ ){
      val = array_from ->get[i].get[ from_row ];
      FloatArrayAdd( &array_to ->get[i], val );
  }  
  
  
  
}



void FA3CPrint( FloatArray3 * data ){
  // FA3C - FloatArray3_COL
  printf("\n");
  int i, j , k;
  for( i = 0 ; i < data ->length; i++ ){
    printf("TABLE %i:\n", i ); 
    for( j = 0 ; j < data->get[i].get[0].length; j++ ){
      for( k = 0 ; k < data->get[i].length; k++ ){
        printf("\t%.2f ", data->get[i].get[k].get[j] ); 
      }
      printf("\n"); 
    }
  }
  
}

void FA2GetLengths( FloatArray * lengths, FloatArray2 * array ){
  int i, L = array -> length; 
  for(i = 0 ; i < L ; i++ ){
    FloatArrayAdd( lengths, array->get[i].length ); 
  }
}
void FA2GetRowDistances( FloatArray * centers , FloatArray2 * values_in_columns,  int skip_class_row_index, FloatArray2 * bufferFATWO, FloatArray * bufferFA ){
  FloatArray * medians = bufferFA;
  FloatArray2GetColumnMedians( medians , values_in_columns, bufferFATWO ); 
  bool VERBOSE = false;
  if(VERBOSE) FloatArrayPrint( medians ); 
  if(VERBOSE) printf("-------------!!\n"); 
  int i , j,  k;
  
  float total;
  float med, val;
  for( j = 0 ; j < values_in_columns->get[0].length; j++ ){
    
    total = 0.0;
    for( i = 0 ; i < values_in_columns->length; i++ ){
      if(i == skip_class_row_index ) continue;
      med = medians->get[i];
      val = values_in_columns->get[i].get[j];
      total += ( med - val ) * ( med - val );    
      if(VERBOSE) printf( "[row: %i, col: %i]\t(%.2f - %.2f) * (%.2f - %.2f) = %.2f \n",  j, i, med , val,med , val, ( med - val ) * ( med - val ) );
      //printf("%.2f\n", med); 
    }
    total = sqrt( total ); 
    if(VERBOSE) printf("total-distance: %f\n-----------------------\n\n", total  ); 
    FloatArrayAdd( centers, total );
    //break;
  }
}


void FloatArray3Instantiate2D1( FloatArray3 * array, int K ){
  int i;
  for( i = 0; i < K; i++ ){
    FloatArray3AddNew( array );
    FloatArray2Reset( &array ->get[ array ->length-1]); 
  }
}

FloatArray3 * FloatArray3New(){
  FloatArray3 * floats;
  FloatArray3Constr( floats );
  return floats;
}

void FloatArray2Split2( FloatArray2 * values_in_columns_test, FloatArray2 *  values_in_columns, float test_ratio, int number_of_classes, FloatArray3 * buf  ){
    bool VERBOSE = false;
    int train_values_n = values_in_columns->get[0].length;
    int test_values_n = (train_values_n * test_ratio);
    int COLUMN_CLASS_ENUM = values_in_columns -> length - 1;
    FloatArray3AddNew( buf );
    FloatArray2 * buffer2A = &buf->get[ buf ->length -1 ];
    FloatArray3AddNew( buf );
    FloatArray2 * buffer2B = &buf->get[ buf ->length -1 ];
    FloatArray2AddNew( buffer2B, 0.0f );
    FloatArray * buffer1A = &buffer2B ->get[ buffer2B ->length - 1 ];
    FloatArray2AddNew( buffer2B, 0.0f );
    FloatArray * buffer1B = &buffer2B ->get[ buffer2B ->length - 1 ];  //if(VERBOSE)printf("total: %i\t test: %i\t train: %i\n", values_in_columns->get[0].length, train_values_n, test_values_n); 
    
    FloatArray * counts = buffer1A;
    FloatArrayReset( counts );
    FloatArrayInstantiate( counts , number_of_classes, 0.0f );
    int cls;
    int L = values_in_columns ->get[ COLUMN_CLASS_ENUM ].length; 
    int i;
    for(i = 0; i < L; i++ ){
        cls = values_in_columns ->get[ COLUMN_CLASS_ENUM ].get[i]; 
        counts->get[cls]++;
    }
    int min = FloatArrayGetMin( counts ); 
    //FloatArrayPrint( counts );
    int size_train, size_test;
    size_test = test_ratio * (float) min;
    size_train = min - size_test;
    //printf("!!!!!!! MIN %i, %i, %i \n", min, size_train, size_test );
   
    FloatArray * buf2 = buffer1B;
    FloatArrayReset( buf2 );
    FloatArray2 * copy = buffer2A;
    FloatArray2Reset( copy );
    FloatArray2CopyToFrom( copy , values_in_columns , buf2 );
    FloatArray2Reset( values_in_columns ); 
    
    FloatArray2Initialize2D1( values_in_columns, copy -> length );
    FloatArray2Initialize2D1( values_in_columns_test ,  copy -> length );
    
    
    
    
    
    
    
    int number_of_divisions = 2;
    int j, k;
    int temp_size;
    bool match;
    int cls_search;
    int row;
    for( i = 0; i < number_of_classes; i++ ){
      cls = i;
      temp_size = size_train;
      for( j = 0 ; j < copy->get[COLUMN_CLASS_ENUM].length; j++ ){
          cls_search = copy->get[ COLUMN_CLASS_ENUM ].get[ j ];
          match = cls == cls_search;
          
          if( match ){
            if(VERBOSE)printf("class search %i\t class found: %i\n", cls, cls_search);
            row = j; 
            FloatArray2CopyRowFromTo_COLUMN( copy ,values_in_columns, j ); 
            FloatArray2RowErase_COLUMN( copy , j, -1 );
            temp_size--;
            if( temp_size < 1 ) break;
          }
      }
      
      
      
      cls = i;
      temp_size = size_test;
      for( j = 0 ; j < copy->get[COLUMN_CLASS_ENUM].length; j++ ){
        cls_search = copy->get[ COLUMN_CLASS_ENUM ].get[ j ];
        match = cls == cls_search;
        
        if( match ){
          if(VERBOSE)printf("class search %i\t class found: %i\n", cls, cls_search);
          row = j; 
          FloatArray2CopyRowFromTo_COLUMN( copy ,values_in_columns_test, j ); 
          FloatArray2RowErase_COLUMN( copy , j, -1 );
          temp_size--;
          if( temp_size < 1 ) break;
        }
      }
      
      
      
      
    }
  
    if(VERBOSE)printf("------------------------------------\n");
    for( j = 0 ; VERBOSE && j < values_in_columns->get[0].length; j++ ){
      printf("[%i] ", j ); FloatArray2PrintRow(values_in_columns, j );
    }
    if(VERBOSE)printf("------------------------------------\n");
    for( j = 0 ; VERBOSE && j < values_in_columns_test->get[0].length; j++ ){
      printf("[%i] ", j ); FloatArray2PrintRow(values_in_columns_test, j );
    }
    if(VERBOSE)printf("------------------------------------\n");
    for( j = 0 ; VERBOSE && j < copy->get[0].length; j++ ){
       printf("[%i] ", j ); FloatArray2PrintRow(copy, j );
    }
    
    FloatArrayFill( counts, 0 );
    for(i = 0; i < copy->get[0].length; i++ ){
      cls = copy ->get[ COLUMN_CLASS_ENUM ].get[i]; 
      if(cls == -1)continue;
      counts->get[cls]++;
    }
    if(VERBOSE)FloatArrayPrint( counts );
    for(i = 0; i < counts->length; i++ ){
     if(counts->get[i] != 0 ) counts->get[i] *= test_ratio;
     counts->get[i] = (int)counts->get[i];
    }
    if(VERBOSE)FloatArrayPrint( counts );
    
    
    for( i = 0; i < number_of_classes; i++ ){
      cls = i;
      temp_size = counts->get[i];
      for( j = 0 ; j < copy->get[COLUMN_CLASS_ENUM].length; j++ ){
        cls_search = copy->get[ COLUMN_CLASS_ENUM ].get[ j ];
        match = cls == cls_search;
        if( match ){
          if(VERBOSE)printf("class search %i\t class found: %i\n", cls, cls_search);
          row = j; 
          FloatArray2CopyRowFromTo_COLUMN( copy ,values_in_columns_test, j ); 
          FloatArray2RowErase_COLUMN( copy , j, -1 );
          temp_size--;
          if( temp_size < 1 ) break;
        }
      }
    }
    
    if(VERBOSE)printf("------------------------------------\n");
    for( j = 0 ; VERBOSE && j < copy->get[0].length; j++ ){
      printf("[%i] ", j ); FloatArray2PrintRow(copy, j );
    }
    
 
    cls = -1;
    for(i = 0 ;  i < copy->get[0].length; i++ ){
      cls_search = copy->get[ COLUMN_CLASS_ENUM ].get[ i ];
      match = cls != cls_search;
      if(match){
        
        FloatArray2CopyRowFromTo_COLUMN( copy ,values_in_columns, i ); 
        FloatArray2RowErase_COLUMN( copy , i, -1 );
      }
      
    }
    if(VERBOSE)printf("------------------------------------\n");
    for( j = 0 ; VERBOSE && j < copy->get[0].length; j++ ){
      printf("[%i] ", j ); FloatArray2PrintRow(copy, j );
    }
    
}
void FloatArray2ToStringf( FloatArray2 * floats , char * f, String * out ){
  char buf[1000];
  int i,j;
  int cols = floats->length;
  int rows = floats ->get[0].length;
  
  printf("!!!!\n"); 
  for(i = 0 ; i < rows; i++ ){
    for(j = 0 ; j < cols; j++ ){
      //sprintf (buf, f , floats->get[j].get[i] );
      //StringAppendString2( out , buf );
    }
    //StringAppendString2( out , "\n" );
  }
}


void floatToStringf( float val , char * f, String * out ){
  char buf[20];
  sprintf (buf, f , val );
  StringAppendString2( out , buf );
}

void FloatArrayToStringf( FloatArray * floats , char * f, String * out ){
  char buf[1000];
  int i,j;
  int L = floats->length;
  int count = 0;
  
  float val;
  
  for(i = 0 ; i < L; i++ ){
    
    
    val = floats->get[i];
    
    
    sprintf (buf, f , val );
    StringAppendString2( out , buf );
    
    
    
  }
}

void FloatArrayToStringBr( FloatArray * floats , int br, String * out ){
  char buf[1000];
  int i,j;
  int L = floats->length;
  int count = 0;
  char * f1 = (char*)"%.2f";
  char * f2 = (char*)"%.0f";
  char * f;
  float val;
  
  for(i = 0 ; i < L; i++ ){
    
    
    val = floats->get[i];
    
    f = val < 1 ? f1 : f2;
    sprintf (buf, f , val );
    StringAppendString2( out , buf );
    StringAppendString2( out , (char*)"\t" );
    if( count++ > br - 3 ) count = -1;
    if( count == 0 ) StringAppendString2( out , (char*)"\n" );  
    
  }
}

void StringArrayToString( StringArray * SA,String * out  ){
  int i;
  for(i = 0 ; i < SA->length; i++ ){
    StringAppendString2( out , SA->get[i].get );
    StringAppendChar( out , ' ' );
  }
}


 void StringArrayFree( StringArray * strings ){
 int i;
 int L1 = strings ->length;
 String * str;
 for( i = 0 ; i < L1; i++ ){
   str = &strings ->get[i];
   StringFree( str ); 
 }
 strings->length = -1;
 strings->alloc = -1;
 strings->i = -1;
 }
 

 
 void FloatArray2Free( FloatArray2 * floats ){
   int i;
   int L1 = floats ->length;
   FloatArray * flts;
   for( i = 0 ; i < L1; i++ ){
     flts = &floats ->get[i];
     FloatArrayFree( flts ); 
   }
   floats->length = -1;
   floats->alloc = -1;
   floats->i = -1;
 }

void StringAddFloatArray2( FloatArray2 * floats2D, String * out ){
  
  int COLS = floats2D->length;
  int ROWS = floats2D->get[0].length;
  int i, j;
  float val;
  for(i = 0 ; i < ROWS; i++ ){
    for(j = 0 ; j < COLS; j++ ){
      val = floats2D->get[j].get[i];
      floatToStringf( val, (char*)"%.2f ", out );
    }
    StringAppendChar( out, '\n');
  }
}


void StringArrayReplaceWithFloat( StringArray * strings, char * find, float value ){
  bool VERBOSE = false;
  int index = StringArrayContains( strings, find );
  char* format = (char*)"%.0f";
  while(true){
    index = StringArrayContains( strings, find );
    if(VERBOSE) printf("found at index %i\n", index ); 
    if(index == -1 )break;
    StringReset( &strings ->get[index] );
    StringAppendFloatf( &strings ->get[index], value, format ); 
    //printf("%s\n",strings ->get[index].get);
    
  }
}



void StringArrayReplaceWithString( StringArray * strings, char * find, char * replacement ){
  bool VERBOSE = false;
  int index = StringArrayContains( strings, find );
  while(true){
    index = StringArrayContains( strings, find );
    if(VERBOSE) printf("found at index %i\n", index ); 
    if(index == -1 )break;
    StringReset( &strings ->get[index] );
    StringAppendString2( &strings ->get[index], replacement ); 
  }
}

void FloatArray2COLGetIndicesOfRowsContaining( FloatArray * indices, FloatArray2 * data_by_col, float val ){
  bool VERBOSE = false;
  int i, j;
  int L1, L2;
  bool match;
  L1 = data_by_col -> length;
  L2 = data_by_col ->get[0].length;
  for( j = 0 ; j < L2; j++ ){
    for( i = 0 ; i < L1; i++ ){
      match = data_by_col ->get[i].get[j] == (float) val;
      if(VERBOSE)printf("[%i,%i]\t%f == %f : %i \n", j, i, data_by_col ->get[i].get[j], val, match ); 
      if(match){FloatArrayAdd( indices , j ); break;}
      
    }  
  }
}


void StringArrayToStringBr( String * out , StringArray * SA , int br){
  int i;
  int count = 0;
  for(i = 0 ; i < SA->length; i++ ){
    StringAppendString2( out , SA->get[i].get );
    StringAppendChar( out , '\t' );
    if( count ++ >= br - 1){ 
      count = 0; 
      StringAppendChar( out , '\n' );    
    }
    
  }
}

void FloatArray2COLRemoveRows( FloatArray2 * data_by_col, FloatArray * indices_of_rows_to_remove ){
  int i, j;
  int L1 = indices_of_rows_to_remove->length;
  int index_to_remove;
  FloatArray * col;
  for( i = L1 - 1; i >= 0; i-- ){
    index_to_remove = indices_of_rows_to_remove ->get[i];
    FloatArray2COLRemoveRow( data_by_col, index_to_remove ); 
  }
}



void FA2RmvCol( FloatArray2 * data_by_col , int index_to_remove ){
  int i, L1 = data_by_col->length;
  FloatArray * row;
  for( i = 0 ; i < L1; i++ ){
      row = &data_by_col->get[i];
      FARmvCol( row, index_to_remove ); 
  }
}


void FA2RmvIndices( FloatArray2 * array , FloatArray * indices ){
    FloatArraySortDsc( indices ); 
    FloatArray * fa, *fb;
    int index;
    int i, j, L = indices->length, L2 = array->length;
    for( i = 0; i < L; i++ ){
        index = indices-> get[i];
        
        for( j = index; j < L2 - 1; j++ ){
          fa = &array->get[ j ];
          FloatArrayReset( fa ); 
          fb = &array->get[j + 1];
          FloatArrayCopyToFrom( fa, fb );
        }
        array->length--;
    }
}

int FAMostCommonValueIndex( FloatArray * values, FloatArray2 * buf  ){
  FloatArray2Reset( buf ); 
  FloatArray * buf1 = FloatArray2GetEmpty( buf );
  FloatArray * buf2 = FloatArray2GetEmpty( buf );
  FloatArrayGetUnique( buf1, values );
  FACountValues( buf2 , values, buf1 );
  int index = FloatArrayGetIndexOfMax( buf2 );
  return index;
}

int FAMostCommonValueIndexOfNum3( FloatArray * vector, float zro, float one, float nul_val, FloatArray2 * buf ){
  int index;
  
  FloatArray2Reset( buf ); 
  FloatArray * buf1 = FloatArray2Next( buf ); 
  FloatArray * buf2 = FloatArray2Next( buf ); 
  
  FloatArray * values = buf1, * counts = buf2;
  
  FloatArrayAdd( values , zro ); 
  FloatArrayAdd( values , one ); 
  FloatArrayAdd( values , nul_val ); 
  
  FACountValues( counts , vector, values );
  
  index = FloatArrayGetIndexOfMax( counts );
  return index;
}

int FASecondMostCommonValueIndexOfNum3( FloatArray * vector, float zro, float one, float nul_val, FloatArray2 * buf ){
  int index;
  
  FloatArray2Reset( buf ); 
  FloatArray * buf1 = FloatArray2Next( buf ); 
  FloatArray * buf2 = FloatArray2Next( buf ); 
  
  FloatArray * values = buf1, * counts = buf2;
  
  FloatArrayAdd( values , zro ); 
  FloatArrayAdd( values , one ); 
  FloatArrayAdd( values , nul_val ); 
  
  FACountValues( counts , vector, values );
  
  index = FloatArrayGetIndexOfMax( counts );
  counts -> get [ index ] = -1;
  index = FloatArrayGetIndexOfMax( counts );
  return index;
}

/*
int FASecondMostCommonValueIndexOfNum3( FloatArray * values, float zro, float one, float nul_val, FloatArray2 * buf2, FloatArray * buf1  ){
  FloatArrayReset( buf ); 
  FloatArrayAdd( buf1 , zro ); 
  FloatArrayAdd( buf1 , one ); 
  FloatArrayAdd( buf1 , nul ); 
  FloatArray2Reset( buf2 ); 
  FACountValues( buf2 , values, buf1 );
  float val1 = buf2->get[0];
  float val2 = buf2->get[1];
  float val3 = buf2->get[2];
  
 if( val2 >= val1 && val2 <= val3 ) return 1;
 if( val2 <= val1 && val2 >= val3 ) return 1;
 
 if( val1 >= val2 && val1 <= val3 ) return 0;
 if( val1 <= val2 && val1 >= val3 ) return 0;
  
  if( val3 >= val2 && val3 <= val1 ) return 2;
  if( val3 <= val2 && val3 >= val1 ) return 2;
  
  return -1;
}
*/

int FASecondMostCommonValueIndex( FloatArray * values, FloatArray2 * buf  ){
  FloatArray2Reset( buf ); 
  FloatArray * buf1 = FloatArray2GetEmpty( buf );
  FloatArray * buf2 = FloatArray2GetEmpty( buf );
  FloatArrayGetUnique( buf1, values );
  FACountValues( buf2 , values, buf1 );
  int index = FloatArrayGetIndexOfMax( buf2 );
  buf2->get[ index ] = -1;
  index = FloatArrayGetIndexOfMax( buf2 );
  return index;
}

void FA2RmvIndicesTEST(){
  
  FloatArray2 T2; FloatArray2Constr( &T2 ); FloatArray2 * t2 = &T2;
  FloatArray  T1; FloatArrayConstr(  &T1 ); FloatArray  * t1 = &T1;
  float num;
  num = 0.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  
  FloatArrayReset( t1 ); 
  num = 1.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  
  FloatArrayReset( t1 ); 
  num = 2.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  
  FloatArrayReset( t1 ); 
  num = 3.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  
  FloatArrayReset( t1 ); 
  num = 4.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  
  FloatArrayReset( t1 ); 
  num = 5.0f;
  FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); FloatArrayAdd( t1 , num ); 
  FloatArray2Add( t2, t1 ); 
  FA2Printfln( t2, "%.0f "); 
  
  FloatArrayReset( t1 ); 
  FloatArray * ind = t1;
  
  for( int i = 0 ; i < 6; i++ ){
    
    if( i == 2 ) continue;
    FloatArrayAdd( ind , i );
  
  }

  printf("\n");
  
  printf("removing:[0,1,2,3,5] (in any order). Remaining: \n");
  FA2RmvIndices( t2 , ind );
  
  FA2Printfln( t2, "%.0f "); 
}
bool FAEqual( FloatArray * one, FloatArray * two ){
  bool VERBOSE = false;
    if( one->length != two->length ) return false;
    if( one->length == 0 ) return true;
    int i, L = one->length;
    float val1, val2;
    for(i = 0 ; i < L; i++ ){
      val1 = one->get[i];
      val2 = two->get[i];
      if( val1 != val2 ) return false;
    }
    return true;
}


int FloatArray2IndexOf(  FloatArray2 * vector_array, FloatArray * vector ){
    int index = -1, i, L = vector_array->length;
    FloatArray * vec1, *vec2;
    bool found;
    for(i = 0 ; i < L; i++ ){
      vec1 = &vector_array->get[i];
      vec2 = vector;
      found = FAEqual( vec1, vec2 );
      if(found) return i;
    }
  return index;
}
  
  void FA2AddCol( FloatArray2 * array, FloatArray * col ){
    int i , L = array->length < col->length ? array->length : col->length;
    FloatArray * fa;
    for(i = 0 ; i < L; i++ ){
      fa = &array->get[i];
      FloatArrayAdd( fa, col->get[i] );
    }
  }
int FA2CountCommonElements( FloatArray2 * one , FloatArray2 * two ){
  int L1 = one->length;
  int L2 = two->length;
  bool eq;
  int count = 0;
  FloatArray * fa, *fb;
  
  for(int i = 0 ; i < L1; i++ ){
    fa = &one->get[i];
    for(int j = 0 ; j < L2; j++ ){
      fb = &two->get[j];  
      eq = FAEqual( fa, fb ); 
      if( eq ){
        count++;
        break;
      }
    }
  }
  return count;
}
  
  FloatArray2 * FA2RmvValues0(  FloatArray2 * values, FloatArray2 * matches, FloatArray2 * buffer ){
    // modifies directly using buffer-copyover, rather than copying to new array
    // optimized for space over time
    FloatArray2Reset( buffer );
    FloatArray * fa, * fb;
    bool same, add;
    int val1, val2;
    int i, j,k,  L = values->length, L2 = matches->length;
    for( i = 0 ; i < L; i++ ){
      fa = &values->get[i];
      same = false;
      add = false;
      for( j = 0; j < L2; j++ ){
          fb = &matches->get[j];
          same = FAEqual( fa, fb );
          if(same)break;
          if( j == L2 - 1 ) add = true;
      }
      if( add )FloatArray2Add( buffer, fa );
    }
    return buffer;
  }

  FloatArray2 * FA2RmvValues3000( FloatArray2 * values, FloatArray2 * matches, FloatArray3 * mem  ){
    FloatArray2 * unique = FloatArray3Next( mem );
    int i, j,k,  L = values->length, L2 = matches->length, L3;
    bool same, skip;
    int val1, val2;
    FloatArray * fa, * fb;
    for( i = 0 ; i < L; i++ ){
      fa = &values->get[i];
      for( j = 0; j < L2; j++ ){
        fb = &matches->get[j];
        L3 = fb->length;
        for(k = 0 ; k < L3; k++ ){
          val1 = fa->get[k];
          val2 = fb->get[k];
          same = val1 == val2;
          if( !same ) break;
        }
        if( same ){}
      }
      if(skip) continue;
      else{
        FloatArray2Add( unique, fa ); 
      }
    }
    return unique;
  }

FloatArray2 * FA2RmvValues3( FloatArray2 * values, FloatArray2 * matches, FloatArray3 * mem  ){
    bool VERBOSE = true;
    FloatArray2 * unique = FloatArray3Next( mem );
    //FloatArray * test = FloatArray2Next( unique );
    //FloatArrayAdd( test , 0.0f ); FloatArrayAdd( test , 0.0f ); FloatArrayAdd( test , 0.0f ); FloatArrayAdd( test , 0.0f ); 
    
    int i, j,k,  L = values->length, L2 = matches->length;
    bool same, add;
    int val1, val2;
    FloatArray * fa, * fb;
    
    printf("L1,L2 = %i,%i\n", L, L2 );
    for( i = 0 ; i < L; i++ ){
        fa = &values->get[i];
        same = false;
        add = false;
        for( j = 0; j < L2; j++ ){
            fb = &matches->get[j];
            same = FAEqual( fa, fb ); 
            if(VERBOSE)printf("%c:\t", same ? 'T' : 'F');
            if(VERBOSE)FAPrintf( fa, "%2.0f"); 
            if(VERBOSE)printf("\t");
            if(VERBOSE)FAPrintfln( fb, "%2.0f");
            if(same){
              if(VERBOSE)printf("found one so skip\n");
              break;
            }
            if( j == L2 - 1 ){
              if(VERBOSE)printf("did not find:");
              if(VERBOSE)FAPrintf( fa , "%3.0f "); 
              
              if(VERBOSE)printf("\n");
              add = true;
            } 
        }
        if( add ){
          if(VERBOSE)printf("Adding in:");
          if(VERBOSE)FAPrintfln( fa, "%3.0f");
          //FloatArray2Add( unique, fb ); 
          FloatArray2Add( unique, fa );
        }
        
    }
    return unique;
}

int FloatArray2CountExist( FloatArray2 * values , FloatArray * floats ){
  FloatArray *fa, *fb;
  int count = 0;
  bool found;
  int i = 0, L = values->length;
  for(i = 0 ; i < L; i++ ){
    fa = &values->get[i];
    fb = floats;
    found = FAEqual( fa ,fb ); 
    if(found) count++;
  }
  return count;
}



void FA2CRmvCol( FloatArray2 * data_by_col , int index_to_remove ){
    int i, j, f;
    FloatArray * col;
    int L1 = data_by_col->length, L2;
    if( index_to_remove == L1 - 1){
        f = data_by_col->length - 1;
        FloatArrayReset( &data_by_col->get[f] );
    }
    for( i = index_to_remove + 1; i < L1; i++ ){
        L2 = data_by_col->get[i].length;
        for( j = 0 ; j < L2; j++){
            data_by_col->get[i - 1].get[j] = data_by_col->get[i].get[j];
        }
    }
    data_by_col->length--;
}

void FloatArray2COLRemoveCol( FloatArray2 * data_by_col , int index_to_remove  ){
    FA2CRmvCol( data_by_col, index_to_remove);
}
  
void FloatArray2COLRandomizeRows( FloatArray2 * data_by_cols, FloatArray2 * buffers ){
  FloatArray2Reset( buffers ); 
  FloatArray * buf1 = FloatArray2Next( buffers );
  FloatArray * buf2 = FloatArray2Next( buffers );
  FloatArray * indices = buf2;
  FloatArrayReset( buf1 );
  FloatArrayReset( indices ); 
  FloatArrayInstantiateAsc( indices, data_by_cols->get[0].length );
  FloatArrayShuffle( indices );
  FloatArray2SetIndicesByMap( data_by_cols , indices, buf1 );
}

float rnd( float num , int decimals ){ 
  float divisor = 10.0f * (decimals - 1);
  int number = (num *= 100.0f );
  return number / 100.0f;
}

void FloatArray2COLRemoveRow( FloatArray2 * data_by_col, int index_to_remove ){
  int i, j;
  int L2 = data_by_col->length;
  FloatArray * col;
  for( j = 0; j < L2; j++ ){
    col = &data_by_col ->get[j];
    FloatArrayRemoveIndex( col , index_to_remove );
  }
}

void FloatArray2Round( FloatArray2 * floats, int decimals  ){
  int i, j;
  int L1 = floats -> length;
  int L2;
  float val, val_before;
  for( i = 0 ; i < L1; i++ ){
    L2 = floats ->get[i].length;
    for( j = 0 ; j < L2; j++ ){
      val_before = floats ->get[i].get[j];
      val = rnd( floats ->get[i].get[j] , decimals ); 
      floats ->get[i].get[j] = val;
      //printf(" %f -> %f \n", val_before, val ); 
    }
    
    
  }
  
}

void FACGetRow( FloatArray * row, FloatArray2 * floats, int row_n  ){
  int i = 0;
  int L = floats->length;
  for( i = 0 ; i < L ; i++ ){
    FloatArrayAdd( row, floats->get[i].get[row_n]); 
  }
}

void FAMapSorted( FloatArray * indices, FloatArray2 * floats1, FloatArray2 * floats2 ){
  

  
  FloatArray * fa1, *fa2;
  bool equal;
  
  
  for( int i = 0; i < floats1->length; i++ ){
    fa1 = &floats1->get[i];
    for( int j = 0; j < floats2->length; j++ ){
      fa2 = &floats2->get[j];
      equal = FAEqual( fa1 , fa2 );
      if( equal ){
        FloatArrayAdd( indices , j ); 
        fa1->length--;
      }
    }
  }
  
}

float FASimilarityRatio( FloatArray * one ,FloatArray * two){
  bool VERBOSE = false;
  int i, L = one->length, cnt = 0;
  float v1, v2;
  bool same;
  float val;
  for( i = 0 ; i < L; i++ ){
    v1 = one -> get [i];
    v2 = two -> get [i];
    same = (v1 == v2);
    val = cnt == 0 || L == 0 ? 0 : (float) cnt / i;
    if(VERBOSE) printf("(%.2f)\t%.2f  c  %.2f\n", val, v2, v2);
    if( same ) cnt++;
  }
  if( cnt == 0 || L == 0 ) return 0;
  return (float) cnt / L;
  
}





void FA2GetLengthFromTo( FloatArray * array_of_lengths, FloatArray3 * one, int from, int to  ){
  FloatArrayReset( array_of_lengths );
  int i, L = (to) <= one->length ? (to) : one->length;
  int length;
  for( i = from ; i < L; i++ ){
    length = one->get[i].length;
    FloatArrayAdd( array_of_lengths, length ); 
  }
}
void FASeqBy( FloatArray * numbers, float times, float inc_amt){
  int i, L = times + 1;
  float amt = 0.0f;
  for(i = 0 ; i < L ; i++ ){
    FloatArrayAdd( numbers, amt ); 
    amt += inc_amt;
  }
}
void FA3SortByIndex2Length( FloatArray3 * data ){
    bool VERBOSE = false;
    int i, j, L = data->length;;
    FloatArray2   * buf2A  = FloatArray3Next( data );
    FloatArray    * buf1A  = FloatArray2Next( buf2A ); 
    FloatArray    * lengths= buf1A;
    
    FloatArray2   * buf2B  = FloatArray3Next( data ); 

    if(VERBOSE)FloatArrayReset( lengths ); 
    if(VERBOSE)FA2GetLengthFromTo( lengths, data, i, L ); 
    if(VERBOSE)FAPrintfln( lengths, "%.0f "); 
    
    int index;
    for(i = 0 ; i < L ; i++ ){
        FloatArrayReset( lengths ); 
        FA2GetLengthFromTo( lengths, data, i, L ); 
        index = FloatArrayGetIndexOfMax( lengths ) + i;
      
        // A -> B
        FloatArray2Reset( buf2B ); 
        FloatArray2CopyToFrom2( buf2B, &data->get[i] );
        
        // C -> A
        FloatArray2Reset( &data->get[i] ); 
        FloatArray2CopyToFrom2( &data->get[i], &data->get[index] );
        
        // B -> C
        FloatArray2Reset( &data->get[index] ); 
        FloatArray2CopyToFrom2( &data->get[index], buf2B  );
        
    }
    
    if(VERBOSE)FloatArrayReset( lengths ); 
    if(VERBOSE)FA2GetLengthFromTo( lengths, data, 0, L ); 
    if(VERBOSE)FAPrintfln( lengths, "%.0f "); 
    
    data->length -= 2;
    
  
}

void FA3PrintAsCol( FloatArray3 * floats, StringArray * sa  ){
  
  FA3SortByIndex2Length( floats ); 

  int i , j , k;
  int L1 = floats->length;
  int L2 = floats->get[0].length;
  int L3;// = viewer->get[0].get[0].length;;
  float val;
  char * space;
  int spaces;// = floats->get[0].get[0].length;
  
  
  
  for( j = 0; j < L2; j++){
    
    for( i = 0; i < L1; i++){
      L3 = floats->get[i].get[j].length;
      if( L3 == 0 ){
        spaces = floats->get[i].get[0].length;
        for( k = 0; k < spaces; k++ ) printf(" ");
      }
      for( k = 0; k < L3; k++){
        if(val >= 100 ) space = " ";
        else if(val >= 10)space = "  ";
        else space = "   ";
        val = floats->get[i].get[j].get[k];
        printf(sa->get[i].get, val);
        
      }  
      printf("\t");
      
    }
    printf("\n");
  }
  
  
  
  
}

void FA2FA2Printfln( FloatArray2 * one, FloatArray2 * two , char * f1, char * f2, FloatArray3 * viewer, StringArray * bufferSA  ){
  
  FloatArray3Reset( viewer ); 
  FloatArray3Add( viewer , one ); 
  FloatArray3Add( viewer , two ); 

  // set format
  StringArrayReset( bufferSA );
  StringArrayAdd( bufferSA , f1 );
  StringArrayAdd( bufferSA , f2 );
  
  FA3PrintAsCol( viewer, bufferSA );
  
  
  
  
}

int FASimilarityT( FloatArray * one ,FloatArray * two){
  bool VERBOSE = false;
  int i, L = one->length;
  float v1, v2, cnt;
  bool same;
  float val;
  for( i = 0 ; i < L; i++ ){
    v1 = one -> get [i];
    v2 = two -> get [i];
    same = (v1 == v2);
    if( same ) cnt++;
    //if(VERBOSE) printf("(%.2f)\t%.2f  c  %.2f\n", val, v2, v2);
  }
 return cnt;
}

int FASimilarityF( FloatArray * one ,FloatArray * two){
  int i, L = one->length;
  int similar = FASimilarityT( one, two ); 
  return L - similar;
}
void FloatArray2SetIndicesByMap( FloatArray2 * array , FloatArray * map, FloatArray * buffer ){
    int i;
    int L = array->length;
    FloatArray * FA;
    for(i = 0 ; i < L ; i++ ){
        FA = &array->get[i];
        FloatArrayReset( buffer );
        FloatArraySetIndicesByMap( FA , map, buffer );
    }
}

void FloatArray2PrintRow( FloatArray2 * array , int row ){
  int i = row, j;
  float val;
  for( j =0 ; j < array->length; j++ ){
    val = array ->get[j].get[ row ];
    
    printf("%.2f ", val);
    
  }
  printf("\n");
  
}

void FAGetIndicesNonmatchingValues( FloatArray * indices, FloatArray * one, FloatArray * two ){
  int i, L = (one -> length) <= (two -> length) ? one->length : two ->length;
  float v1, v2;
  bool dif;
  for( i = 0 ; i < L; i++ ){
    v1 = one -> get [i];
    v2 = two -> get [i];
    dif = (v1 != v2);
    if(dif) FloatArrayAdd( indices, i );
  }
}


void FAPrintL( FloatArray * fa ){
  printf("L: %i\n", fa->length ); 
}

void FA2PrintL( FloatArray2 * fa ){
  printf("L: %i\n", fa->length ); 
}

void FA3PrintL( FloatArray3 * fa ){
  printf("L: %i\n", fa->length ); 
}

void FA4PrintL( FloatArray4 * fa ){
  printf("L: %i\n", fa->length ); 
}

int FACountCommonElements( FloatArray * a, FloatArray * b ){
  int count = -1;
  int i, j, L1 = a->length, L2 = b->length;
  float v1, v2;
  for(i = 0 ; i < L1; i++ ){
      v1 = a->get[i];
      for(j = 0 ; j < L2; j++ ){
          v2 = b->get[j];    
          if( v1 == v2 ){
            if(count == -1) count++;
            count++;
            break;
          }
      }
  }
  return count;
}

void FAGetIndicesOfMatchingIndexValues( FloatArray * indices, FloatArray * one, FloatArray * two, float u1, float u2 ){
  int i, L = (one -> length) <= (two -> length) ? one->length : two ->length;
  float v1, v2;
  bool at;
  for( i = 0 ; i < L; i++ ){
    v1 = one -> get [i];
    v2 = two -> get [i];
    at = u1 == v1 && u2 == v2; 
    if(at) FloatArrayAdd( indices, i );
  }
}

FloatArray* FAGetIndicesNonmatchingValuesAt3( FloatArray * one, FloatArray * two, float u1, float u2, FloatArray2 * bufferFA2  ){
  FloatArray * indices = FloatArray2Next( bufferFA2 );
  int i, L = (one -> length) <= (two -> length) ? one->length : two ->length;
  float v1, v2;
  bool at;
  for( i = 0 ; i < L; i++ ){
    v1 = one -> get [i];
    v2 = two -> get [i];
    at = u1 == v1 && u2 == v2; 
    if(at) FloatArrayAdd( indices, i );
  }
  return indices;
}


void FloatArraySortMap2( FloatArray * map, FloatArray * unsorted , FloatArray * sorted, FloatArray * bufferFA ){
  FloatArray * copy = bufferFA;
  FloatArrayReset( bufferFA );
  FloatArrayCopyFromTo( unsorted , copy ); 
  bool VERBOSE = false;
  int L = sorted -> length;
  int i , j;
  float val1, val2;
  for(i = 0 ; i < L; i++  ){
    val1 = sorted->get[ i ];
    if(VERBOSE) printf("searching for value %f @ index: ", val1 ); 
    for( j = 0 ; j < L; j++ ){
      val2 = copy->get[ j ];
      if(VERBOSE) printf("%i ", j ); 
      // if( VERBOSE ) printf("[%.2f],[%.2f]\n", val1, val2); 
      if( val1 == val2 ){ 
        if(VERBOSE) printf("\n\tfound %.3f (%.3f) @ index %i\n", val1, val2, j); 
        //printf("(%f,%f)index %i to %i == %i\n", val1, val2, i , j, i== j);
        copy->get[ j ] = MIN; 
        FloatArrayAdd( map , j ); 
        break; 
      }
      
    }
    
  }
  
  
}

int floatcompAsc(const void* elem1, const void* elem2){
  if(*(const float*)elem1 < *(const float*)elem2) return -1;
  return *(const float*)elem1 > *(const float*)elem2;
}

int floatcompDsc(const void* a, const void* b){
  if(*(const float*)a > *(const float*)b) return -1;
  return *(const float*)a < *(const float*)b;
}


void FloatArraySortAsc( FloatArray * floats ){
  bool VERBOSE = false;
  int i;
  qsort (floats->get , floats->length, sizeof(float), floatcompAsc );
  if( VERBOSE ) for (i=0; i<floats->length; i++) printf ("%.2f ",floats->get[i]);
}

void FloatArraySortDsc( FloatArray * floats ){
  bool VERBOSE = false;
  int i;
  qsort (floats->get , floats->length, sizeof(float), floatcompDsc );
  if( VERBOSE ) for (i=0; i<floats->length; i++) printf ("%.2f ",floats->get[i]);
}

void FloatArrayGetUnique( FloatArray * unique_values, FloatArray * values ){
  bool add;
  int i , j;
  float val;
  for(i = 0; i < values->length; i++ ){
    val = values -> get[i];
    add = !FloatArrayContains( unique_values, val);
    if( add ) FloatArrayAdd( unique_values , val );
  }
  FloatArraySortAsc( unique_values );
}

void FloatArrayFill( FloatArray * fill , float val ){
  int i;
  for( i = 0 ; i < fill -> length ; i ++ ){
    fill ->get[i] = val;
    
  }
  
}

void FloatArray2TotalFrom( FloatArray * totals, FloatArray2 * floats, int from_col ){
    int i;
    int val;
    for( i = 0 ; i < floats -> length; i++ ){
        val = FloatArrayTotalFrom( &floats ->get[i], from_col );
        FloatArrayAdd( totals , val ); 
    }
}



float FloatArrayTotalFrom( FloatArray * floats, int from_col ){
  int i, j;
  int L2, L1 = floats ->length;
  float outcome = 0.0f, val;
  for(i = from_col; i < L1 ; i++ ){
    val = floats->get[i];
    outcome += val;
  }
  return outcome;
}


float FATotalFromTo( FloatArray * floats, int from_col , int to_col ){
  int i, j;
  int L1 = to_col + 1 > floats ->length || to_col == - 1 ? floats ->length : to_col + 1;
  float outcome = 0.0f, val;
  for(i = from_col; i < L1 ; i++ ){
    val = floats->get[i];
    outcome += val;
  }
  return outcome;
}

void FloatArraySetAll( FloatArray * floats , float val ){
  int i, L = floats->length;
  for(i = 0 ; i < L; i++ ){
    floats->get[ i ] = val;
  }
}
void FloatArrayInstantiate( FloatArray * array, int number_of_indicies_desired, float value  ){
  int i;
  FloatArrayReset( array );
  for(i = 0 ; i < number_of_indicies_desired; i++ ) FloatArrayAdd( array , value ); 
}

void FloatArrayInstantiateAsc( FloatArray * array, int number_of_indicies_desired  ){
  int i;
  for(i = 0 ; i < number_of_indicies_desired; i++ ) FloatArrayAdd( array , i ); 
}

void FloatArrayInitialize( FloatArray * array, int number_of_indicies_desired ){
  int i;
  for(i = 0 ; i < number_of_indicies_desired; i++ ) FloatArrayAdd( array , -1 ); 
}

void FloatArrayShuffle( FloatArray * array ){
  srand((unsigned)time(NULL));
  int i, n, t;
  n = array->length;
  for (int i = 0; i < n - 1; i++) {
    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
    t = array->get[j];
    array->get[j] = array->get[i];
    array->get[i] = t;
  }
}

void FloatArrayGetUniqueCountsFast( FloatArray * counts, FloatArray * unique_values, FloatArray * values ){
  // uses enumerated indices. For example class 0, will be counted at index 0.
  // thus if values other than indices are used, this will not work
  int i;
  int index;
  FloatArrayInitialize( counts, unique_values->length );
  for( i = 0 ; i < values->length; i++ ){
    index = (int) values->get[ i ];
    counts->get[ index ] += 1;
  }
  
}

void FloatArrayGetValueSet( FloatArray * indices , FloatArray * sorted ){
  // REQUIRES SORTED ARRAY
  // returns array of the index of first occurance of a each particiualr value 
  // one of each value, no duplicates 
  
  int i , j, k;
  int L = sorted->length;
  float val_this, val_prev = sorted -> get [0];
  FloatArrayAdd( indices , 0 );
  for( i = 0 ; i < L; i++ ){
    val_this = sorted -> get [i];
    if( val_this != val_prev ) FloatArrayAdd( indices , i );
    val_prev = val_this;
  }
}

bool fequal(float a, float b)
{
  float epsilon = 0.0000001;
  return fabs(a-b) < epsilon;
}

void FloatArrayGetValueSet2( FloatArray * indices , FloatArray * sorted ){
  // REQUIRES SORTED ARRAY
  // returns array of the index of first occurance of a each particiualr value 
  // one of each value, no duplicates 
  bool VERBOSE = false;
  bool same;
  int i , j, k;
  int L = sorted->length;
  float val_this, val_prev = sorted -> get [0];
  int int1, int2;
  val_prev = sorted -> get [0]; 
  FloatArrayAdd( indices, 0 );
  for( i = 0 ; i < L; i++ ){
    val_this = sorted -> get [i];
    int1 = (val_prev * 100000);
    int2 = (val_this * 100000);
    same = int1 == int2;//fequal(val_this, val_prev ); 
    if(VERBOSE)printf("[%i]\t (%f=%f)(%i=%i) == %s\n", i, val_prev, val_this, int1, int2, same ? "T" : "F"); 
    
    if( !same ){
        FloatArrayAdd( indices , i );
        
    }
    val_prev = val_this;    
  }
}

bool FloatArrayContains( FloatArray * floats, float value ){
  int i;
  for( i = 0 ; i < floats->length; i++ ){
    if( floats->get[i] == value ) return true;   
  }
  return false;
}
void FloatArray2Print( FloatArray2 * values ){
  
  for( int i = 0 ; i < values -> length ; i++ ){
    printf("column:%i\n", i );
    for( int j = 0 ; j < values->get[i].length; j ++ ){
      
      printf("%.3f ",  values->get[i].get[j]);  
      
    }
    printf("\n" );
  }
}


void FloatArrayIndicesContainingMax( FloatArray * indices, FloatArray * values){
  int i;
  int L1 = values -> length;
  float max = MIN, val;
  for( i = 0 ; i < L1; i++ ){
    val = values ->get[i];
    if( val > max ) max = val;
  }
  for( i = 0 ; i < L1; i++ ){
    val = values ->get[i];
    if( val == max ) FloatArrayAdd( indices, i);
  }
}


void FloatArrayGetMaxValIndicesFrom( FloatArray * indices, FloatArray * data, int from ){
  float val;
  int start_col = from;
  int j , k;
  int max = FloatArrayGetMaxFrom( data , start_col );
  for( k = start_col ; k < data -> length; k++ ){
    val = data -> get[k];
    if(val == max){ FloatArrayAdd(indices, k );}
  }
}

void FloatArraySubtractAll( FloatArray * values , float amt ){
  int i;
  for(i = 0 ; i < values ->length; i++ ){
    values->get[i] -= amt;
  }
}

void FloatArrayInverseAll( FloatArray * values , float inv ){
  int i;
  for(i = 0 ; i < values ->length; i++ ){
    values->get[i] = inv - values->get[i];
  }
}

void FAMultiply( FloatArray * values , float amt ){
  int i;
  for(i = 0 ; i < values ->length; i++ ){
    values->get[i] *= amt;
  }
}

void FADivide( FloatArray * values , float amt ){
  int i;
  if( amt != 0 ){
      for(i = 0 ; i < values ->length; i++ ){
        if(values->get[i] == 0 ) continue;
        values->get[i] /= amt;
      }
  } else {
    for(i = 0 ; i < values ->length; i++ ){
        values->get[i] = 0;
    }
  }
}

float divide0( float val1, float val2 ){
  return (val1 == 0 || val2 == 0 ) ? 0 : val1 / val2;
}
void FADivideBy( FloatArray * one, FloatArray * two ){
  // divides A[i] by B[i]
  int i, L = one->length <= two->length ? one->length : two->length;
  float val1, val2, valx;
  for( i = 0 ; i < L; i++ ){
      val1 = one->get[i];
      val2 = two->get[i];
      one->get[i] = divide0( val1, val2 ); ;
  }
}

void FAIfLessThanSetTo( FloatArray * floats, float val, float setTo  ){
  int i, L = floats -> length;
  float ths;
  for( i = 0 ; i < L ; i++ ){
      ths = floats->get[i];
      if( ths < val ) floats->get[i] = setTo;
  }
}

void FAIfGreaterThanSetTo( FloatArray * floats, float val, float setTo ){
  int i, L = floats -> length;
  float ths;
  for( i = 0 ; i < L ; i++ ){
    ths = floats->get[i];
    if( ths > val ) floats->get[i] = setTo;
  }
}
void FAAdd( FloatArray * values , float amt ){
  int i;
  for(i = 0 ; i < values ->length; i++ ){
    values->get[i] += amt;
  }
}

void FASub( FloatArray * values , float amt ){
  int i;
  for(i = 0 ; i < values ->length; i++ ){
    values->get[i] -= amt;
  }
}
void FloatArrayMultiply( FloatArray * values , float amt ){
    FAMultiply( values, amt ); 
}


void FANormalize( FloatArray * floats ){
  
  int L1 = floats->length;
  int i;
  float v, mn, mx, rng;

  mn = MAX;
  mx = MIN;
  for( i = 0 ; i < L1; i++ ){
    v = floats->get[ i ];
    if( v < mn ) mn = v;
    if( v > mx ) mx = v;
  }
  
  rng = mx - mn;
  for( i = 0 ; i < L1; i++ ){
    floats->get[ i ] -= mn;
    floats->get[ i ] /= rng;
  }
  
  
}
void FloatArrayNormalize( FloatArray * floats, int dimensions ){
  int len = floats->length;
  int i, j, index;
  float v, mn, mx, rng;
  for( j = 0 ; j < dimensions; j++ ){
    mn = MAX;
    mx = MIN;
    for( i = 0 ; i < len; i+= dimensions ){
      index = ( i + j );
      v = floats->get[ index ];     // printf("by col(%i)(%i): %f\n", index ,j, v ); 
      if( v < mn ) mn = v;
      if( v > mx ) mx = v;
    }
    rng = mx - mn;
    for( i = 0 ; i < len; i+= dimensions ){
      index = ( i + j );
      floats->get[ index ] -= mn;
      floats->get[ index ] /= rng;
    }
  }
}
int FA2CMaxIndexFromTo( FloatArray2 * values, int row, int from, int to ){
  bool VERBOSE = false;
  float val, max = MIN;
  int i;
  int index;
  bool greater;
  int col1 = from == -1 ? 0 : from;
  int col2 = ( to == -1 || to + 1 > values->get[0].length) ? values->get[0].length : to;
  int L1 = col2 + 1;
  for(i =col1 ; i < L1; i++ ){
      val = values ->get[ row ].get[i ];
      greater = val > max;
      if(greater){
          max = val;
          index = i;
      }
      if(VERBOSE)printf("val %f\n", val ); 
  }
  return index;
}

int FloatArrayCOLGetIndexColMax( FloatArray2 * values, int col_index ){
  //DEPRICATED
  int j; 
  int L = values ->length;
  int index = - 1;
  float val, max = MIN;
  bool greater, VERBOSE = false;
  for(j = 0 ; j < L; j++ ){
    val = values ->get[ j ].get[ col_index ];
    if(VERBOSE)printf("val %f\n", val ); 
    greater = val > max;
    if(greater){
      max = val;
      index = j;
    }
  }
  if(VERBOSE)printf("max val %f\t(%i)\n", values ->get[ index ].get[ col_index ], index ); 
  return index;
}



////////////////////////// FLOAT ARRAY 2D //////////////////////////




void FloatArray2Constr( FloatArray2 * floats ){
  floats->length = 0;
  floats->alloc = 0;
  floats->i = 0;
  FloatArray2PreventOverflow( floats );
}
void FloatArray2Reset( FloatArray2 * floats ){
  int i = 0;
  for( i = 0 ; i < floats->length; i++ ){
    FloatArrayReset( &floats->get[i] ); 
  }
  floats->length = 0;
  floats->i = 0;
}

void FloatArray2COLAdd( FloatArray2 * floats, FloatArray * num  ){
  // takes an array and places each index at the end of each array in FA2COL
  // FA2COL is an array stored by col as opposed to by row
  int L = floats ->length;
  int i;
  for( i = 0 ; i < L; i++ ){
    FloatArrayAdd( &floats->get[ i ] , num->get[i] ); 
  }
  FloatArray2PreventOverflow( floats );
}

void FloatArray2COLAddRowFA2COL( FloatArray2 * floats, FloatArray2 * num, int index  ){
  // copies one FA2COL row to another FA2COL 
  // FA2COL is an array stored by col as opposed to by row
  int L = num ->length;
  int i;
  printf("!\n"); 
  
  
  for( i = 0 ; i < L; i++ ){
    
    FloatArrayAdd( &floats->get[i] , 0.0f );   
    printf(" %.2f ", num->get[i].get[index] ); 
  }
  printf("\n"); 
  FloatArray2PreventOverflow( floats );
}
void FloatArray2Add( FloatArray2 * floats, FloatArray * num  ){
  int index = (floats->length), i;
  floats->length++;
  FloatArrayConstr( &floats->get[ index ] );
  for( i = 0 ; i < num->length; i++ ){
    //printf("\tadding value (%f) to index %i\n",num->get[i] , index); 
    FloatArrayAdd( &floats->get[ index ] , num->get[i] ); 
  }
  FloatArray2PreventOverflow( floats );
}

void FloatArray2AddNew( FloatArray2 * floats, float num ){
    floats->length++;
    int index = (floats->length - 1), i;
    FloatArrayConstr( &floats->get[ index ] );
    FloatArrayAdd( &floats->get[ index ] , num ); 
    FloatArray2PreventOverflow( floats );
}

void FloatArray2AddEmpty( FloatArray2 * floats ){
FloatArray2AddNew( floats, 0.0f ); 
FloatArrayReset( &floats->get[ floats->length-1]); 
}

FloatArray *  FloatArray2GetEmpty( FloatArray2 * floats ){
  FloatArray2AddNew( floats, 0.0f ); 
  FloatArrayReset( &floats->get[ floats->length-1]); 
  return &floats->get[ floats->length-1];
}

void FloatArray3AddEmpty( FloatArray3 * floats ){
  FloatArray3AddNew( floats ); 
  FloatArray2Reset( &floats->get[ floats->length-1]); 
}

float FA2MaxColVal( FloatArray2 * fa2, int col ){
  float result;
  int i, j , L1, L2;
  L1 = fa2 -> length;
  float max = MIN, val;
  for( i = 0 ; i < L1; i++ ){
    val = fa2->get[i].get[ col ];
    if(val > max ) max = val;
  }
  return max;
}
void FA2Printf( FloatArray2 * fa2, char * f ){
  int i, j;
  for( i = 0 ; i < fa2->length; i++ ){
    for( j = 0 ; j < fa2->get[i].length; j++ ){
      printf( f, fa2->get[i].get[j] ); 
    }
  }
  
}

void FA2PrintflnSub( FloatArray2 * fa2, char * f, int from, int toLength ){
  int i, j;
  for( i = from ; i < toLength; i++ ){
    for( j = 0 ; j < fa2->get[i].length; j++ ){
      printf( f, fa2->get[i].get[j] ); 
    }
    printf("\n");
  }
  
}

void FA2Printfln( FloatArray2 * fa2, char * f ){
  int i, j;
  for( i = 0 ; i < fa2->length; i++ ){
    for( j = 0 ; j < fa2->get[i].length; j++ ){
      printf( f, fa2->get[i].get[j] ); 
    }
    printf("\n");
  }
}


void FA2CPrintfln( FloatArray2 * fa2, char * f ){
  int i, j;
  for( j = 0 ; j < fa2->get[0].length; j++ ){
    for( i = 0 ; i < fa2->length; i++ ){
      printf( f, fa2->get[i].get[j] ); 
    }
    printf("\n");
  }
}

void FA2CPrintf( FloatArray2 * fa2, char * f ){
  int i, j;
  for( j = 0 ; j < fa2->get[0].length; j++ ){
    for( i = 0 ; i < fa2->length; i++ ){
      printf( f, fa2->get[i].get[j] ); 
    }
    printf("\n");
  }
  
}


void FACPrintf( FloatArray * fa, char * f ){
  int i, j;

    for( i = 0 ; i < fa->length; i++ ){
      printf( f, fa->get[i] ); 
    }
}

void FA3CPrintfln( FloatArray3 * data, char * f ){
  // D2 is FA2C
  int i;
  for(  i = 0 ; i < data->length; i++ ){
    FA2CPrintfln( &data->get[i], f  );
    PrintSection('-', 50 );
  }
}
void FAIndicesOf( FloatArray * indices, FloatArray * values, float val ){
  int i;
  int L1 = values -> length;
  float fnd;
  for( i = 0 ; i < L1; i++ ){
    fnd = values ->get[i];
    if( val == fnd ) FloatArrayAdd( indices, i);
  }
}

void FAGetIndices( FloatArray * values, FloatArray * data, FloatArray * indices ){
  int i;
  int L1 = indices->length;
  int index;
  float val;
  for( i = 0 ; i < L1; i++ ){
    index = indices->get[i];
    val = data -> get [index];
    FloatArrayAdd( values, val);
  }
}

void FACountValues( FloatArray * counts, FloatArray * data, FloatArray * values_to_count ){
  int i , j;
  int L1 = values_to_count->length, L2 = data->length;
  float val, fnd;
  int cnt;
  for( i = 0 ; i < L1; i++ ){
    cnt = 0;
    val = values_to_count->get[i];
    for( j = 0; j < L2; j++ ){
      fnd = data->get[j];
      if(val == fnd ) cnt++;
    }
    FloatArrayAdd( counts, cnt );
  }
}

void FACPrintfBr( FloatArray * fa, char * f, int br ){
  int i, j;
  int count = 0;
  for( i = 0 ; i < fa->length; i++ ){
    printf( f, fa->get[i] ); 
    if( count++ == br ){
      count = -1;
      printf("\n");
    }
  }
  printf("\n");
}
void FloatArray2AddToLast( FloatArray2 * floats, float num  ){
  int index = (floats->length) - 1;
  FloatArrayAdd( &floats->get[ index ] , num ); 
}



void FA2Normalize_ROOT( FloatArray2 * floats, int skip, bool VERBOSE ){
  int i, j;
  int L1 = floats -> length, L2;
  float min, max, range;
  FloatArray * col;
  for(i = 0; i < L1; i++ ){
    if( i == skip ) continue;
    col = &floats -> get[i];
    min = FloatArrayGetMin( col );
    max = FloatArrayGetMax( col ); 
    range = max - min;
    L2 = col -> length;
    if(VERBOSE) printf("COL MAX: %f \t MIN: %f \t RANGE: %f\n", min, max, range);
    for(j = 0 ; j < L2; j++ ){
      if(VERBOSE) printf("%.2f ", col->get[ j ] ); 
      col->get[ j ] -= min;
      col->get[ j ] /= range;
    }
    if(VERBOSE) printf("\n\n"); 
  }
}

void FloatArray2COLNormalize( FloatArray2 * floats ){
  // DEPRICATED
  bool VERBOSE = false;
  int DONT_SKIP_ANY_COLUMNS = -1;
  FA2Normalize_ROOT(floats, DONT_SKIP_ANY_COLUMNS , VERBOSE ); 
}

void FA2Normalize( FloatArray2 * floats ){
    bool VERBOSE = false;
    int DONT_SKIP_ANY_COLUMNS = -1;
    FA2Normalize_ROOT(floats, DONT_SKIP_ANY_COLUMNS , VERBOSE ); 
}

void FA2NormalizeSkip( FloatArray2 * floats, int COL_TO_SKIP ){
  bool VERBOSE = false;
  FA2Normalize_ROOT(floats, COL_TO_SKIP , VERBOSE ); 
}
void FloatArray2AddToLastAll( FloatArray2 * floats, FloatArray * additions  ){
  int index = (floats->length) - 1;
  FloatArray  * subarray = &floats->get[ index ];
  float val;
  int i, L1 = additions ->length;
  for( i = 0 ; i < L1; i++ ){
    val = additions -> get [i];
    FloatArrayAdd( subarray , val ); 
  }
}

float FloatArray2TotalRowFromCol( FloatArray2 * floats, int row, int from_col){
  float val = 0.0f;
  int i;
  int L1 = floats ->get[row].length;
  for(i = from_col; i < L1; i++){
    val += floats ->get[row].get[i];
  }
  return val;
}

void FloatArray2DivideColByCol( FloatArray * new_col, FloatArray2 * values, int col1, int col2 ){
  int i, j;
  int L1, L2;
  float v1, v2, v;
  L1 = values ->length;
  for( i = 0 ; i < L1; i++ ){
    v1 = values -> get[i].get[col1];
    v2 = values -> get[i].get[col2];
    v = v1 == 0 || v2 == 0 ? 0.0f : v1 / v2;
    FloatArrayAdd( new_col, v ); 
  }
}

void FA2CMultiplyColByCol( FloatArray * new_col, FloatArray2 * values, int col1, int col2 ){
  int i, j;
  int L1, L2;
  float v1, v2, v;
  L1 = values ->get[0].length;
  //printf("len = %i\n", L1 ); 
  for( i = 0 ; i < L1; i++ ){
    v1 = values -> get[col1].get[i];
    v2 = values -> get[col2].get[i];
    v = v1 * v2;
    FloatArrayAdd( new_col, v ); 
  }
}

void FA2CHypotenuseColByCol( FloatArray * new_col, FloatArray2 * values, int col1, int col2 ){
  int i, j;
  int L1, L2;
  float v1, v2, v;
  L1 = values ->get[0].length;
  //printf("len = %i\n", L1 ); 
  for( i = 0 ; i < L1; i++ ){
    v1 = values -> get[col1].get[i];
    v2 = values -> get[col2].get[i];
    v = sqrt(pow(v1,2) + pow(v2,2));
    FloatArrayAdd( new_col, v ); 
  }
}
void FloatArray2COLPrintRow( FloatArray2 * floats, int row_index ){
  // untested
  int i , j;
  int cols = floats ->length;
  for(i = 0 ; i < cols; i++ ){
    printf("%.2f ", floats->get[i].get[row_index]); 
  }
  printf("\n"); 
}

void FloatArray2GetRow( FloatArray * row, FloatArray2 * floats, int row_index ){
  int i , j;
  int cols = floats ->get[0].length;
  for(i = 0 ; i < cols; i++ ){
    FloatArrayAdd( row , floats->get[row_index].get[ i]);
  }
}

void FloatArray2AddCol( FloatArray2 * data, FloatArray * col ){
  int i , j;
  int L1 = data -> length;
  FloatArray * floats;
  for( i =0 ; i < L1; i++ ){
    floats = &data ->get[i];
    FloatArrayAdd( floats , col->get[i] ); 
  }
}

float FloatArray2Get( FloatArray2 * floats, int row, int col ){
  
  return floats ->get[row].get[col];
}
int FloatArray2GetRowIndexFirstOccuranceCol( FloatArray2 * floats, int col, float val ){
  int i;
  float search;
  int L1 = floats -> length;
  for( i =0 ; i < L1; i++ ){
    search = floats -> get[i].get[col];
    if( search == val ) return i;
    
  }
  return -1;
}

int FloatArrayGetIndexFirstOccurance( FloatArray * floats, float val ){
  int i;
  float search;
  for( i =0 ; i < floats -> length; i++ ){
    search = floats -> get[i];
    if( search == val ) return i;
    
  }
  return -1;
}
void FloatArray2AddTo( FloatArray2 * floats, int row, float num  ){
  FloatArrayAdd( &floats->get[ row ] , num ); 
}

int FloatArrayGetMinDistanceIndex( FloatArray * floats ){
  float min = MAX;
  int index = -1;
  int i;
  for( i = 0 ; i < floats->length; i++  ){
    if (floats->get[i] < min){
      min = floats->get[i];
      index = i;
    }
  }
  return index;
}




void FloatArray2InitializeD1( FloatArray2 * values, int number_of_top_dimensions, FloatArray * bufferFA ){
  int i;
  for( i = 0; i < number_of_top_dimensions; i++ ){
    FloatArrayReset( bufferFA ); 
    FloatArrayAdd( bufferFA, -1 ); 
    FloatArray2Add( values, bufferFA );
    FloatArrayReset( &values->get[ values->length - 1 ] ); 
  }
}

void FloatArray2Initialize2D1( FloatArray2 * values, int number_of_top_dimensions ){
  int i;
  int f;
  FloatArray2Reset( values );
  for( i = 0; i < number_of_top_dimensions; i++ ){
      f =  values->length++;
      FloatArray2PreventOverflow( values );  
      FloatArrayConstr( &values->get[ f ] ); 
  }
}





void FloatArray2ToRows( FloatArray2 * values_in_columns, FloatArray * values , int number_of_columns, FloatArray * bufferFA  ){
  int i, j, idx;
  int number_of_rows = values->length / number_of_columns;
  float val;
  //printf("number of rows: %i\n", number_of_rows); 
  for(i = 0 ; i < number_of_rows; i++ ){
    FloatArrayReset( bufferFA ); 
    for(j = 0 ; j < number_of_columns; j++ ){
      idx = ( i * number_of_columns ) + j;
      val = values->get[idx];
      FloatArrayAdd( bufferFA , val );
    }
    FloatArray2Add( values_in_columns , bufferFA );
  }
} 

void FloatArray2ToColumns( FloatArray2 * values_in_columns, FloatArray * values , int number_of_columns, FloatArray * bufferFA  ){
  int i, j, idx;
  int number_of_rows = values->length / number_of_columns;
  float val;
  //printf("number of rows: %i\n", number_of_rows); 
  for(j = 0 ; j < number_of_columns; j++ ){
    
    FloatArrayReset( bufferFA ); 
    for(i = 0 ; i < number_of_rows; i++ ){
      idx = ( i * number_of_columns ) + j;
      val = values->get[idx];
      FloatArrayAdd( bufferFA , val );
    }
    FloatArray2Add( values_in_columns , bufferFA );
  }
}


void FloatArray2GetIndicesByClass( FloatArray2 * indices, FloatArray * class_column, int number_of_classes, FloatArray * bufferFA ){
  FloatArray2InitializeD1( indices, number_of_classes , bufferFA);
  int i, j;
  int class_index;
  
  for( j = 0 ; j < class_column->length; j++ ){
    class_index = class_column->get[j];//printf("%i ", class_index ); 
    FloatArrayAdd( &indices->get[class_index], j );
  }
  
}





void FloatArray2SortAsc( FloatArray2 * floats ){
  int i;
  for(i = 0; i < floats->length; i++ )
    FloatArraySortAsc( &floats->get[i] ); 
}


void FloatArray2CopyToFrom( FloatArray2 * to, FloatArray2 * from, FloatArray * bufferFA ){
  int i , j;
  for(i = 0 ; i < from->length; i++ ){
    FloatArrayReset( bufferFA ); 
    for(j = 0 ; j < from->get[i].length; j++ ){
      FloatArrayAdd( bufferFA , from->get[i].get[j] );
    }
    FloatArray2Add( to, bufferFA ); 
  }
}

void FloatArray2CopyToFrom2( FloatArray2 * to, FloatArray2 * from ){
  int i , j;
  for(i = 0 ; i < from->length; i++ ){
    FloatArray2AddNew( to, from->get[i].get[0] ); 
    for(j = 1 ; j < from->get[i].length; j++ ){
      FloatArray2AddToLast( to, from->get[i].get[j] ); 
    }
  }
}

void FloatArray2GetColumnMedians( FloatArray * medians , FloatArray2 * values_in_columns ,  FloatArray2 * bufferFATWO ){
  bool VERBOSE = false;
  bool even_number_of_indices;
  int i, j , k;
  float median = 0.0f;
  
  
  // make copy of values
  FloatArray2Reset( bufferFATWO );
  FloatArray2CopyToFrom( bufferFATWO, values_in_columns, medians ); 
  
  // sort values ascending 
  FloatArray2SortAsc( bufferFATWO );
  
  // get the medians of every column and store them in an array
  FloatArrayReset( medians );
  for( i = 0 ; i < bufferFATWO->length; i++ ){
    even_number_of_indices = bufferFATWO->get[i].length % 2 == 0;
    median = 0.0f;
    j = (bufferFATWO->get[i].length - 1) / 2;
    median += bufferFATWO->get[i].get[j];
    //printf("test\n"); 
    if( even_number_of_indices ){
      if(VERBOSE)printf(",%i", j+1);
      median += bufferFATWO->get[i].get[j+1];
      median /= 2;
    }
    FloatArrayAdd( medians , median ); 
  }
  if(VERBOSE)FloatArrayPrintBr( medians , 1);
}


void FloatArray2CopyRow( FloatArray * row , FloatArray2 * data , int row_index ){
  int i, j;
  float val;
  for( i = 0 ; i < data->length; i++ ){
    val = data->get[i].get[ row_index ];
    FloatArrayAdd( row , val ); 
    //printf("%.2f ",  );         
  }
}
void FloatArray2RowSubtractFromBy( FloatArray2 * data , int from, FloatArray * by ){
  int i, j;
  for( i = 0 ; i < data->length; i++ ){
    data->get[i].get[ from ] -= by->get[i];
  }
}


void FloatArray2RowSubtractAllBy( FloatArray2 * data , FloatArray * by ){
  int i, j;
  for( i = 0 ; i < data->length; i++ ){
    FloatArray2RowSubtractFromBy( data, i, by ); 
  }
}

void FloatArray2FilterByClass( FloatArray2 * single_class, FloatArray2 * data, FloatArray2 * class_indices, int class_index, FloatArray * bufferFA ){
  int i, j, index;
  int COLS = data->length;
  float val;
  FloatArray * indices = &class_indices->get[ class_index ];
  for(i = 0 ; i < COLS; i++ ){
    FloatArrayReset( bufferFA ); 
    for( j = 0 ; j < indices->length; j++ ){
      index = indices->get[ j ];
      val = data->get[ i ].get[ index ];
      FloatArrayAdd( bufferFA, val ); 
    }
    FloatArray2Add( single_class, bufferFA );
  }
}


void FARmvCol( FloatArray * floats, int index ){
  int L1 = floats -> length;
  bool remove_last = index == L1 - 1;
  int i;
  if( !remove_last ){
      for( i = index ; i < L1 - 1; i++ ){
          floats -> get[i] = floats -> get[i + 1];
      }
  }
  floats->length--;
}

void FloatArrayRemoveIndex( FloatArray * floats, int index ){
  
  FARmvCol( floats, index ); 
}
void FloatArrayRemoveIndices( FloatArray * floats, FloatArray * indices ){
  int i;
  int L1 = indices -> length;
  int index;
  for(i = L1 -1 ; i >= 0; i--  ){
    index = indices ->get[i];
    FloatArrayRemoveIndex( floats, index ); 
  }
}


void FloatArray2RemoveIndex( FloatArray2 * floats, int index,  FloatArray * buffer  ){
  int i , j;
  for(i = index + 1; i < floats->length; i++ ){
    FloatArrayReset( buffer );  
    for( j = 0 ; j < floats->get[i].length; j++ ){
      FloatArrayAdd( buffer , floats->get[i].get[j] );   
    }
    index = i - 1;
    FloatArrayReset( &floats->get[index] );
    FloatArrayCopyFromTo( buffer , &floats->get[index] );
    
  }
  floats->length--;
}

void FloatArray2RemoveIndexFromTo( FloatArray2 * array, int index1, int index2,  FloatArray * bufferFA){
  bool VERBOSE = false;
  int i;
  for( i = index2; i >= index1; i-- ){
    if(VERBOSE)printf("removing index: %i\n", i );
    FloatArray2RemoveIndex( array, i, bufferFA );
  }
}



float FloatArray2GetRowTotalFromTo(FloatArray2 * segments, int row, int start_index, int end_index ){
  int total = 0, class_total;
  int i , j;
  bool VERBOSE = true;
  float val;
  total = 0; 
  
  int L = end_index + 1 < segments -> get[row].length ? end_index + 1: segments -> get[row].length;
  for( j = start_index ; j < L; j++ ){ 
    val = segments ->get[row].get[j]; 
    total += val;
    if(VERBOSE) printf( "%.2f ", val );
  }
  if(VERBOSE) printf( "\n");
  return total;
}

float FloatArray2GetRowTotal(FloatArray2 * segments, int row, int start_index){
  return FloatArray2GetRowTotalFromTo( segments, row, start_index,segments->length - 1 );
}
void FloatArray2MapApply( FloatArray2 * thresholds , FloatArray * map , FloatArray2 * bufferFATWO, FloatArray * bufferFA ){
  FloatArray2 * copy = bufferFATWO;
  FloatArray2Reset( copy );
  FloatArray2CopyToFrom( copy,  thresholds  , bufferFA );
  FloatArrayReset( bufferFA ); 
  int i, j, index;
  for(i = 0; i < copy->length; i++ ){
    index = map->get[i];
    FloatArrayReset( &thresholds->get[i] ); 
    FloatArrayCopyFromTo( &copy->get[index] , &thresholds->get[i] );
  }
}

void FloatArray2SortSecondary( FloatArray2 * segments, FloatArray2 * double_sort, FloatArray * class_counts, int number_of_classes, int current_dimension, FloatArray * bufferFA  ){
  float val_this, val_prev;
  int i , j, cls;
  bool same;
  val_prev = double_sort -> get[ 0 ].get[ 0 ];
  for( i = 0 ; i < double_sort -> length ; i++ ){
    val_this = double_sort -> get[ i ].get[ 0 ];
    cls = double_sort -> get[ i ].get[ 1 ];
    same = val_this == val_prev;
    if( same && i != double_sort -> length - 1 ){
      class_counts -> get [ cls ]++;
    }
    else{
      FloatArrayAdd( bufferFA , val_prev ); 
      for( j = 0 ; j < class_counts -> length ; j ++ ){
        FloatArrayAdd( bufferFA , class_counts -> get [j] ); 
      }
      
      FloatArray2Add( segments , bufferFA );
      FloatArrayReset( bufferFA );
      FloatArrayReset( class_counts ); 
      FloatArrayInstantiate( class_counts, number_of_classes, current_dimension );
    }
    val_prev = val_this;
    
  }
  
}
void FloatArray2JoinDimension2ToFrom( FloatArray2 * FA2A , FloatArray2 * FA2B ){
  int i, j;
  int L1 = FA2A->length, L2 = FA2B->length, LX;
  bool compatible = L1 == L2, VERBOSE = false;
  if(  compatible ){ 
    for( i = 0; i < L2; i++ ){
      LX = FA2B->get[i].length;
      for( j = 0 ; j < LX; j++ ){
        FloatArrayAdd( &FA2A->get[i], FA2B->get[i].get[j] ); 
      }
    }
  }
  if(VERBOSE) printf("%s\n", compatible ? "T" : "F");
}



void FloatArray2PreventOverflow( FloatArray2 * floats ){
  int INITIAL_AMT = 25;
  float GROWTH = 2.0, THRESHOLD = 1.5;
  if( floats->alloc == 0 ){
    floats->alloc = INITIAL_AMT;
    floats->get = (FloatArray*) malloc( floats->alloc * sizeof(FloatArray) );
  } else {
    float usage = floats->length * THRESHOLD;
    if( usage >= ( floats->alloc  ) ){
      floats->alloc *= GROWTH;
      floats->get = (FloatArray*) realloc( floats->get, floats->alloc * sizeof(FloatArray) );
    }
  }
}


void FloatArray2PrintByRow( FloatArray2 * floats2d, int col_number ){
  int i, j;
  int cols = floats2d->length, rows;
  float val;
  for( j = 0 ; j < cols; j++ ){
    rows = floats2d->get[ j ].length;
    for( i = 0 ; i < rows; i++ ){
      val = floats2d->get[ j ].get[ i ];
      printf("%.4f ", val ); 
    }
    printf("\n"); 
  }
}

void FloatArray2PrintfByRow( FloatArray2 * floats2d, int col_number, char * f  ){
  int i, j;
  int cols = floats2d->length, rows;
  float val;
  for( j = 0 ; j < cols; j++ ){
    rows = floats2d->get[ j ].length;
    for( i = 0 ; i < rows; i++ ){
      val = floats2d->get[ j ].get[ i ];
      printf(f, val ); 
    }
    printf("\n"); 
  }
}


void FA2GetCol( FloatArray * column, FloatArray2 * floats2d, int col_number ){
  bool VERBOSE = false;
  int i, j;
  int rows = floats2d->length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    val = floats2d->get[ i ].get[ col_number ];
    if(VERBOSE)printf("%.2f ", val ); 
    FloatArrayAdd( column, val ); 
    if(VERBOSE)printf("\n"); 
  }
}

void FA2CGetCol( FloatArray * column, FloatArray2 * floats2d, int col_number ){
  bool VERBOSE = false;
  int i, j;
  int rows = floats2d->get[0].length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    val = floats2d->get[ col_number ].get[ i ];
    if(VERBOSE)printf("%.2f ", val ); 
    FloatArrayAdd( column, val ); 
    if(VERBOSE)printf("\n"); 
  }
}


void FA2CGetRow( FloatArray * row, FloatArray2 * fa2c, int row_number ){
  bool VERBOSE = false;
  float val;
  int i, j;
  int L = fa2c->length;
  for( i = 0 ; i < L; i++ ){
    val = fa2c->get[ i ].get[ row_number ];
    FloatArrayAdd( row, val ); 
    
  }
}


void FloatArray2COLGetCol( FloatArray * column, FloatArray2 * floats2d, int col_number ){
  FA2CGetCol( column, floats2d, col_number );
}

void FA2CDeleteColumn( FloatArray2 * floats, int index  ){
  int i , j;
  int from_col, to_col;
  int L1 = floats->length, L2;
  for( i = index ; i < L1 - 1; i++ ){
      L2 = floats->get[index].length;
      for( j = 0 ; j < L2; j++ ){
          from_col = i+1;
          to_col = i;
          floats->get[ to_col ].get[i] = floats->get[ from_col ].get[i];
      }
  }
  floats->length--;
}

void FloatArray2GetCol( FloatArray * column, FloatArray2 * floats2d, int col_number ){
  bool VERBOSE = false;
  int i, j;
  int rows = floats2d->length;
  int cols = floats2d->length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    val = floats2d->get[ i ].get[ col_number ];
    if(VERBOSE)printf("%.2f ", val ); 
    FloatArrayAdd( column, val ); 
    if(VERBOSE)printf("\n"); 
  }
}
void FloatArray2PrintfByCol( FloatArray2 * floats2d, int col_number, char * format){
  int i, j;
  int rows = floats2d->get[0].length;
  int cols = floats2d->length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    for( j = 0 ; j < cols; j++ ){
      
      val = floats2d->get[ j ].get[ i ];
      printf(format, val ); 
    }
    printf("\n"); 
  }
}

void StringAppendFloatf( String * string, float flt, char * f ){
  char buf[20];
  sprintf( buf, f, flt ); 
  StringAppendString2( string,  buf );
  //StringAppendString2( string , "222" ); 
}

void FloatArray2COLPrint( FloatArray2 * floats2d, int col_number ){
  int i, j;
  int rows = floats2d->get[0].length;
  int cols = floats2d->length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    for( j = 0 ; j < cols; j++ ){
      
      val = floats2d->get[ j ].get[ i ];
      printf("%.2f\t", val ); 
    }
    printf("\n"); 
  }
}




void FloatArray2COLPrintExIEqual( FloatArray2 * floats2d, FloatArray * cols_to_print, int col_to_check, float value ){
  int i, j;
  int rows = floats2d->get[0].length;
  int cols = cols_to_print->length;
  float val;
  int col;
  int count = 1;
  for( i = 0 ; i < rows; i++ ){
    if( floats2d->get[ col_to_check ].get[ i ] != value) continue;
    printf("[%i]\t", count++ ); 
    for( j = 0 ; j < cols; j++ ){
      col = cols_to_print ->get[j];
      val = floats2d->get[ col ].get[ i ];
      printf("%.2f\t", val  ); 
    }
    printf("\n"); 
  }
}

void FloatArray2COLPrintExI( FloatArray2 * floats2d, FloatArray * cols_to_print ){
  int i, j;
  int rows = floats2d->get[0].length;
  int cols = cols_to_print->length;
  float val;
  int col;
  for( i = 0 ; i < rows; i++ ){
    printf("[%i]\t", i); 
    for( j = 0 ; j < cols; j++ ){
      col = cols_to_print ->get[j];
      val = floats2d->get[ col ].get[ i ];
      printf("%.2f\t", val  ); 
    }
    printf("\n"); 
  }
}
void FloatArray2COLPrinti( FloatArray2 * floats2d, int col_number ){
  int i, j;
  int rows = floats2d->get[0].length;
  int cols = floats2d->length;
  float val;
  for( i = 0 ; i < rows; i++ ){
    printf("[%i]\t", i); 
    for( j = 0 ; j < cols; j++ ){
      
      val = floats2d->get[ j ].get[ i ];
      printf("%.2f\t", val ); 
    }
    printf("\n"); 
  }
}




void FloatArray2COLGetIndexColMax( FloatArray * indices, FloatArray2 * values  ){
  int start_index = 1;
  int L = values ->get[start_index].length;
  int i;
  int max_index;
  for(i = start_index ; i < L; i++ ){
    max_index = FloatArrayCOLGetIndexColMax( values , i);
    FloatArrayAdd( indices , max_index );
  }
}



////////////////////////// FLOAT ARRAY 3D //////////////////////////

void FloatArray3PreventOverflow( FloatArray3 * floats ){
  int INITIAL_AMT = 25;
  float GROWTH = 2.0, THRESHOLD = 1.5;
  if( floats->alloc == 0 ){
    floats->alloc = INITIAL_AMT;
    floats->get = (FloatArray2*) malloc( floats->alloc * sizeof(FloatArray2) );
  } else {
    float usage = floats->length * THRESHOLD;
    if( usage >= ( floats->alloc  ) ){
      floats->alloc *= GROWTH;
      floats->get = (FloatArray2*) realloc( floats->get, floats->alloc * sizeof(FloatArray2) );
    }
  }
}


void FloatArray3Constr( FloatArray3 * floats ){
  floats->length = 0;
  floats->alloc = 0;
  floats->i = 0;
  FloatArray3PreventOverflow( floats );
}



void FAGetIndicesWhereColValuesChange( FloatArray * indices, FloatArray2 * array, int col ){
    int i , j, f = array->length-1;
    int prv = array->get[0].get[ col ], ths;
    bool dif;
    FloatArrayAdd( indices, prv ); 
    int L1 = array->length; 
    for( i = 0 ; i < L1; i++ ){
        ths = array -> get[i].get[ col ];
        dif = ths != prv;
        if( dif ){
            prv = ths;
            FloatArrayAdd( indices, prv );
        }
    }
}


void FAGetCol( FloatArray * col_vector, FloatArray2 * fa2, int col_n ){
    int i;
    int L1 = fa2->length;
    for( i = 0 ; i < L1; i++ ){
        FloatArrayAdd( col_vector , fa2->get[i].get[col_n] ); 
    }
}
  
void FAGetIndicesFromTo(FloatArray * fa, int i1, int i2){
  for( int k = i1; k < i2; k++ ){ FloatArrayAdd( fa, k ); }
  
}
void FAGetIndicesStartAndStop( FloatArray * indices_duple, FloatArray * starting_indices, int final_length ){
  // given a list of starting indices, returns duple in array format
  //    for example, given the indices 1, 22 (where something happens for example)
  //    would return 0,1 ... 22, L, where l is the length;
  //    this could be poped into an array: ie: for( i = 0; i < L; i+=2){ i1 = A[i], i2 = A[i+ 1] }
  
  bool VERBOSE = false;
  int L2 = starting_indices -> length;
  int i1, i2;
  int j;
  for( j = 0 ; j < L2; j++ ){
    i1 = ( j == 0 ) ? 0 : starting_indices->get[j-1];
    i2 = starting_indices->get[ j ];
    FloatArrayAdd( indices_duple, i1 ); 
    FloatArrayAdd( indices_duple, i2 ); 
    if(VERBOSE) printf("%i,%i\n", (int)i1,(int)i2);  
  }
  if( j == L2 ){
    i1 = starting_indices->get[j-1];
    i2 = final_length;
    FloatArrayAdd( indices_duple, i1 ); 
    FloatArrayAdd( indices_duple, i2 ); 
    if(VERBOSE) printf("%i,%i\n", (int)i1,(int)i2); 
  }
  
}
  
void FAGetIndexOfAtEveryValueChange( FloatArray * indices, FloatArray * fa ){
  // get the index of evey chage value
  // for example: 111222333 would return: 0,3,6
  // ! use on sorted list
  int i;
  int L1 = fa->length;
  float prv, ths;
  bool dif;
  prv = fa ->get[ 0 ];
  //FloatArrayAdd( indices , 0 ); 
  for( i = 0 ; i < L1; i++ ){
    ths = fa ->get[ i ];
    dif = ths != prv;
    if( dif ){
      //printf("p,t = %.0f,%.0f\n", prv, ths );
        prv = ths;
        FloatArrayAdd( indices , i ); 
        
    }
  }
}
void FA2SortDependentBinary( FloatArray2 * array, int col, int i0, int iF ){
    FloatArray2 BUF0; FloatArray2 * buf0 = &BUF0; FloatArray2Constr( buf0 ); 
    FloatArray2 BUF1; FloatArray2 * buf1 = &BUF1; FloatArray2Constr( buf1 ); 
    FloatArray2 BUFX; FloatArray2 * bufx = &BUFX; FloatArray2Constr( bufx ); 
    FloatArray * fa, *fa2;
      
    if( i0 == -1 ) i0 = 0;
    if( iF == -1 ) iF = array->length;
    int i, j;
    int L1 = iF;
    int val;
    for( i = i0 ; i < L1 ; i++ ){
        fa = &array -> get [ i ];
        val = fa->get[ col ];
        if( val == 0 )  FloatArray2Add( buf0, fa ); 
        if( val == 1 )  FloatArray2Add( buf1, fa ); 
        if( val >  1 )  FloatArray2Add( bufx, fa );
        FloatArrayReset( fa );
    }
    
    i = i0 ;
    
    L1 = buf0->length;
    for( j = 0; j < L1; j++ ){
        fa = &array -> get [ i ++ ];
        fa2= &buf0  -> get [ j ];
        FloatArrayCopyToFrom( fa, fa2); 
    }
    
    L1 = buf1->length;
    for( j = 0; j < L1; j++ ){
        fa = &array -> get [ i ++];
        fa2= &buf1  -> get [ j ];
        FloatArrayCopyToFrom( fa, fa2); 
    }
  
    L1 = bufx->length;
    for( j = 0; j < L1; j++ ){
        fa = &array -> get [ i ++];
        fa2= &bufx  -> get [ j ];
        FloatArrayCopyToFrom( fa, fa2); 
    }
    FloatArray2Free( buf0 );
    FloatArray2Free( buf1 );
    FloatArray2Free( bufx );
}



void FloatArray3Add( FloatArray3 * floats, FloatArray2 * num  ){
  int index = (floats->length), i, j, index2;
  floats->length++;
  FloatArray2Constr( &floats->get[ index ] );
  FloatArray2 * FA2 = &floats->get[ index ];
  for( i = 0 ; i < num->length; i++ ){
    
    FloatArray2Add( FA2 , &num->get[i] ); 
    
  }
  FloatArray3PreventOverflow( floats );
} 







void FA2AddC( FloatArray2 * floats, FloatArray * num ){
    int i, L1 = num->length;
    float val;
    FloatArray * fa;
    for( i = 0 ; i < L1; i++ ){
        val = num->get[i];
        FloatArray2AddNew(floats, val);
    }
}
  
void FloatArray3Reset( FloatArray3 * floats ){
  int i;
  for( i = 0 ; i < floats->length; i++ ){
    FloatArray2Reset( &floats->get[i] ); 
  }
  floats->length = 0;
  floats->i = 0;
}

void FloatArray4Reset( FloatArray4 * floats ){
  int i;
  for( i = 0 ; i < floats->length; i++ ){
    FloatArray3Reset( &floats->get[i] ); 
  }
  floats->length = 0;
  floats->i = 0;
}

void FA3PrintTables( FloatArray3 * FA3 , int cols ){
  int i, j , k, count;
  float val;
  for( i = 0 ; i < FA3->length; i++ ){
    printf("---------------------------\n"); 
    printf("TABLE %i\n", i); 
    printf("---------------------------\n"); 
    for( j =0 ; j < FA3->get[i].length; j++ ){
      count = 0;
      for( k =0 ; k < FA3->get[i].get[j].length; k++ ){
        if(count++ >= cols){ count = 0; printf("\n");}
        val = FA3->get[i].get[j].get[k];
        printf("%.3f ", val);
        
        
      }
      printf("\n");
      
    }
    
  }
}
void FloatArray3PrintTables( FloatArray3 * FA3 , int cols ){
  FA3PrintTables( FA3, cols ); 
}



void FloatArray3InstantiateD1( FloatArray3 * values, int number_of_top_dimensions, FloatArray2 * bufferFA2, FloatArray * bufferFA1 ){
  int i;
  FloatArrayReset( bufferFA1 ); 
  FloatArrayAdd( bufferFA1, -1 ); 
  FloatArray2Reset( bufferFA2 );
  FloatArray2Add( bufferFA2, bufferFA1 );
  for( i = 0 ; i < number_of_top_dimensions; i++ ){
    FloatArray3Add( values , bufferFA2 );
  }
}

void FloatArray3AddNew( FloatArray3 * floats){
  floats->length++;
  int index = (floats->length - 1), i;
  FloatArray2 * FA2 = &floats->get[ index ];
  FloatArray2Constr( FA2 );
  FloatArray2AddNew( FA2 , 0.0f );
  FloatArray3PreventOverflow( floats );
}


////////////////////////// FLOAT ARRAY 4D //////////////////////////

void FloatArray4PreventOverflow( FloatArray4 * floats ){
  int INITIAL_AMT = 25;
  float GROWTH = 2.0, THRESHOLD = 1.5;
  if( floats->alloc == 0 ){
    floats->alloc = INITIAL_AMT;
    floats->get = (FloatArray3*) malloc( floats->alloc * sizeof(FloatArray3) );
  } else {
    float usage = floats->length * THRESHOLD;
    if( usage >= ( floats->alloc  ) ){
      floats->alloc *= GROWTH;
      floats->get = (FloatArray3*) realloc( floats->get, floats->alloc * sizeof(FloatArray3) );
    }
  }
}

void FloatArray4Constr( FloatArray4 * floats ){
  floats->length = 0;
  floats->alloc = 0;
  floats->i = 0;
  FloatArray4PreventOverflow( floats );
}

void FloatArray4Add( FloatArray4 * floats, FloatArray3 * num  ){
  int index = (floats->length), i, j, index2;
  floats->length++;
  FloatArray3Constr( &floats->get[ index ] );
  FloatArray3 * FA2 = &floats->get[ index ];
  for( i = 0 ; i < num->length; i++ ){
    
    FloatArray3Add( FA2 , &num->get[i] ); 
    
  }
  FloatArray4PreventOverflow( floats );
} 


void FloatArray4AddNew( FloatArray4 * floats){
  floats->length++;
  int index = (floats->length - 1), i;
  FloatArray3 * FA3 = &floats->get[ index ];
  FloatArray3Constr( FA3 );
  FloatArray3AddNew( FA3 );
  FloatArray4PreventOverflow( floats );
}

////////////////////////// LINE ARRAY //////////////////////////

void LineArrayReset( LineArray * linearray ){
  linearray->length = 0;
  linearray->i = 0;
}

void LineArrayConstr_R( LineArray * L, int length ){
  float T = 1.5;
  float G = 2.0;
  L->alloc  = length * G;
  L->length = 0;
  L->i = 0;
  L->id = -1;
  L->x1 = (float*)malloc( sizeof( float ) * length * G );
  L->y1 = (float*)malloc( sizeof( float ) * length * G );
  L->x2 = (float*) malloc( sizeof( float ) * length * G );
  L->y2 = (float*)malloc( sizeof( float ) * length * G );
  L->cls = (String*)malloc( sizeof( String ) * length * G );
};
void LineArrayConstr(LineArray * L){
  int inital_mem_alloc = 10;
  LineArrayConstr_R( L, inital_mem_alloc );
}
void LineArrayFree( LineArray * L ){
  free( L->x1 ); 
  free( L->y1 ); 
  free( L->x2 ); 
  free( L->y2 ); 
  StringFree( L->cls ); 
  L->alloc  = -1;
  L->length = -1;
  L->i = -1;
  L->id = -1;
}


void LineArrayAdd( LineArray * L , float x1, float y1, float x2, float y2, char * cls ){
  float G = 2.0;  // growth factor
  float T = 1.5;  // growth threshold
  int CHARS = 100;
  int f = 0; // final index
  
  L->length++;
  if( (float)L->length * T > L->alloc ){
    L->alloc *= 3;
    L->x1 = (float*) realloc( L->x1, sizeof( float ) * L->alloc );
    L->y1 = (float*)realloc( L->y1, sizeof( float ) * L->alloc );
    L->x2 = (float*)realloc( L->x2, sizeof( float ) * L->alloc );
    L->y2 = (float*)realloc( L->y2, sizeof( float ) * L->alloc );
    L->cls = (String*) realloc( L->cls, sizeof( String ) * L->alloc );
  }
  f = L->length - 1;
  L->x1[ f ] = x1;
  L->y1[ f ] = y1;
  L->x2[ f ] = x2;
  L->y2[ f ] = y2;
  StringConstr( &L->cls[ f ] , CHARS );
  StringAppendString2( &L->cls[ f ], cls  );
}

void LineArrayCopyFromTo( LineArray * linearray1 , LineArray * linearray2 ){
  int i;
  LineArrayConstr_R( linearray2 , linearray1->length );
  for( i = 0 ; i < linearray1->length; i++ ){
    LineArrayAdd( linearray2 , linearray1->x1[i], linearray1->y1[i], linearray1->x2[i], linearray1->y2[i], linearray1->cls[i].get ); 
  }
}


void LineArrayParsePointArray( LineArray * L, PointArray * P, int DIMENSIONS ){
  
  int i, j;
  
  printf("Points: %i\n", P->length);
  for( i = 0 ; i < P->length; i+= DIMENSIONS ){
    for( j = 1 ; j < DIMENSIONS; j++ ){
      LineArrayAdd( L , P->x[ i + j - 1 ] , P->y[ i + j - 1 ], P->x[ i + j ], P->y[ i + j ], P->cls[ i + j ].get );
      //printf("ADDING LINE\n");
    }
    
  }
}


void LineArrayPrintTo( LineArray * L , int length ){
  int i;
  int len = 0 + ((length <  L->length && length > 0 ) ? length : L->length);
  int line;
  for( i= 0 ; i < len; i++ ){
    line = floor( i / 2 );
    printf("Rounded(%i) \t%.0f,%.0f\t\t%.0f,%.0f\t\t%s\n", line, round(L->x1[i]), round(L->y1[i]), round(L->x2[i]), round(L->y2[i]), L->cls[i].get ); 
  }
}


void LineArrayPrint( LineArray * p ){
  int i; 
  float a , b, d, e;
  String c;
  for( i = 0 ; i < p->length; i++ ){
    a = p->x1[i];
    b = p->y1[i];
    d = p->x2[i];
    e = p->y2[i];
    c = p->cls[i];
    printf("x1,y1,x2,y2,c = %f,%f,%f,%f,%s\n", a, b, d, e, c.get );
  }
  //printf("len = %i\n", p.length );
}
void LineArrayColocatedPairs( LineArray * lines, float dimensions, float sizeX, float sizeY, float marginX, float marginY, FloatArray * bufferFA ){
  FloatArrayReset( bufferFA ); 
  int i;
  float x, y;
  for( i = 0 ; i < dimensions; i++ ){
    x = (sizeX * i) + marginX;
    y = 100 - marginY;
    LineArrayAdd( lines, x,y,x + (sizeX), y,(char*)"nn");
    LineArrayAdd( lines, x,y,x, y - sizeY ,(char*)"nn");
  }
}


void LineArrayShiftY( LineArray * lines, float amt){
  int i;
  for( i =0 ; i < lines->length; i++ ){
    lines->y1[i] += amt;
    lines->y2[i] += amt;
  }
}

void LineArrayShiftX( LineArray * lines, float amt){
  int i;
  for( i =0 ; i < lines->length; i++ ){
    lines->x1[i] += amt;
    lines->x2[i] += amt;
  }
}


////////////////////////// POINT ARRAY //////////////////////////
void PointArrayConstr( PointArray * p, int length ){
  float T = 1.5;
  float G = 2.0;
  if( length < 10 ) length = 10;
  p->alloc  = length * G;
  p->length = 0;
  p->i = 0;
  p->x = (float*) malloc( sizeof( float ) * length * G );
  p->y = (float*) malloc( sizeof( float ) * length * G );
  p->cls = (String*) malloc( sizeof( String ) * length * G );
};


void PointArrayFree( PointArray * P ){
  free( P->x ); 
  free( P->y ); 
  StringFree( P->cls ); 
  P->alloc  = -1;
  P->length = -1;
  P->i = -1;
}


void PointArrayAdd( PointArray * p , float x, float y, char * cls ){
  
  float G = 2.0;  // growth factor
  float T = 1.5;  // growth threshold
  int CHARS = 100;
  int f = 0; // final index
  
  p->length++;
  if( (float)p->length * T > p->alloc ){
    p->alloc *= G;
    p->x = (float*)realloc( p->x, sizeof( float ) * p->alloc );
    p->y = (float*)realloc( p->y, sizeof( float ) * p->alloc );
    p->cls = (String*) realloc( p->cls, sizeof( String ) * p->alloc );
  }
  f = p->length - 1;
  p->x[ f ] = x;
  p->y[ f ] = y;
  StringConstr( &p->cls[ f ] , CHARS );
  StringAppendString2( &p->cls[ f ], cls );
}


void PointArrayGetFA2CRowToY( PointArray * points , FloatArray2 * floats , int row ){
  bool VERBOSE = false;
  int i , j;
  int L1 = floats->length;
  float val, x = 0.0f;
  char * class_name = (char*) "untitled";
  for( i = 0 ; i < L1; i++ ){
      val = floats->get[i].get[row];
      PointArrayAdd( points, x, val, class_name ); 
      if(VERBOSE)printf("val: %f\n", val ); 
  }
}

void PointArraySetXAll( PointArray * points , float x ){
  int i;
  int L1 = points -> length;
  for( i = 0 ; i < L1; i++ ){
    points->x[i] = x;
    
  }
}

void PointArrayPrint( PointArray * p ){
  float a , b;
  String c;
  int i; for( i = 0 ; i < p->length; i++ ){
    a = p->x[i];
    b = p->y[i];
    c = p->cls[i];
    printf("(x,y,c) = (%f,%f,%s)\n", a, b, c.get );
    
  }
  printf("len = %i\n", p->length );
}

void PointArrayParseFloatArray(  PointArray * points , FloatArray * data, LineArray * grid, StringArray * classes, int DIMENSIONS ){
  int i, j, index, cls, d = DIMENSIONS;
  float x1, y1, x2, y2, x0 , y0, xf, yf, v;
  
  for( i = 0 ; i < data->length; i+= d ){
    for( j = 0 ; j < d; j++ ){
      
      index = ( i + j );
      v = data->get[ index ];     // printf("by col(%i)(%i): %f\n", index ,j, v ); 
      x1 = grid->x1[j];
      y1 = grid->y1[j];
      x2 = grid->x2[j];
      y2 = grid->y2[j];
      x0 = x2 - x1;
      y0 = y2 - y1;
      xf = x1 + ( x0 * v ); 
      yf = y1 + ( y0 * v );
      
      cls = (i + j) / d;
      PointArrayAdd( points , xf, yf, classes->get[ cls ].get  ); //length("here is the string")
    }
  }
}




//////////////////////////////////////////////// UTILITIES ////////////////////////////////////////////////////
//////////////////////////////////////////////// UTILITIES ////////////////////////////////////////////////////
//////////////////////////////////////////////// UTILITIES ////////////////////////////////////////////////////

void initCharArr( char * characters, int length ){ 
  int j; for( j = 0; j < length; j++ ){ characters[j] = '\0';}
  characters[length-1] = '\0';
}

int getIndex( int i, int j, int d ){ return i * d + j;}
 
char * getCOLOR( int class_enum ){
  if( class_enum == 0 ) return (char*)"blue";
  if( class_enum == 1 ) return (char*)"red";
  else return (char*)"black";
}

float min( float one, float two ){
  return one >= two ? two : one;
}

int length(  char * chars ){
  int count = 0, i = 0;
  while( chars[i++] != '\0' ){ count++;}
  return count;
}


float SubstringToFloat( char * str, int index1, int index2 ){
  String string; String * s = &string; StringConstr( s, 100 );
  int result = MIN;
  int i, L1 = length(str);
  for( i = index1 ; i < index2 + 1; i++ ){
    StringAppendChar( s , str[i] );
    if(!isInt( str[i] )){ printf("ERROR:cannot convert alpha to int\n"); break;}
  }
  printf("\n"); 
  float val = atof( s->get ); 
  StringFree(s);
  return val;
}

bool isInt( char c ){
  if( c == '0' ) return true;
  if( c == '1' ) return true;
  if( c == '2' ) return true;
  if( c == '3' ) return true;
  if( c == '4' ) return true;
  if( c == '5' ) return true;
  if( c == '6' ) return true;
  if( c == '7' ) return true;
  if( c == '8' ) return true;
  if( c == '9' ) return true;
  return false;
}

bool isDouble( char c ){ // is int plus .
  if( c == '.' ) return true;
  if( isInt(c) ) return true;
  return false;
}

bool areDoubles( char * c ){ // is int plus .
  int L = length( c ); 
  int i;
  if( L < 1 ) return false;
  for( i =0 ; i < L; i++ ){
    if (isDouble( c[i] )) continue;
    else return false;
  }
  return true;
}
bool isComma( char c ){ if( c == ',' ) return true; return false; }

#endif // STRUCTURES_H_