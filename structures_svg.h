//#include  "structures.h"

#ifndef STRUCTURES_SVG_H_   /* Include guard */
#define STRUCTURES_SVG_H_

void SvgAddRect( String * SVG, FloatArray * floats  , float opacity, char * color );
void SvgAddHyperRect( String * SVG, FloatArray * CLASS, FloatArray * bufferFA, char * color, float size, float sizeY, float marginX, float marginY );
void SvgAddRectRBG( String * SVG  , float x, float y, float w, float h, float opacity, int R, int G, int B );
void SvgAddHyperRectIndex( String * SVG, FloatArray * CLASS, FloatArray * bufferFA, char * color, float size, float sizeY, float marginX, float marginY, int index );
void SvgOpen( String *  save );
void SvgClose( String *  save );
void SvgExport( String * SVG, String * filename_buffer, char * FULL_FILEPATH );
void SvgAddLines( String * SVG, LineArray * grid, char * color, float linewidth, float opacity );
void SvgLabelColocatedRepeat( String * svg, LineArray * lines, char * d1, char * d2   );
void sprintfSVGPointRGBRadius( String *  string, float x1, float y1, float R, float G, float B, float radius, int pointid   );
void sprintfSVGRect(  String *  string , char * stem,  int i , float x, float y, float w, float h, float opacity, char * color  );
void sprintfSVGText( String *  str, float x, float y, char * text );
void sprintfSVGLineBtwSized( String *  save, float x1, float y1, float x2, float y2, char * color  , float width, float opacity, int lineid );

////////////////////////// SVG & SPRINTF //////////////////////////

void SvgAddRectIndex( String * SVG, float y1, float y2, float size, float sizeY, float marginX, float marginY, int index, int R, int G, int B){
  float x, SPC, SZ, t1;
  int i = index;
  x = ((size + 0.01f) * i) + marginX;
  SPC = (1) * size;
  SZ = sizeY * (y2 - y1);
  t1 = (marginY + sizeY) - ((y1) * sizeY) - SZ;
  SvgAddRectRBG( SVG , x, t1, SPC, SZ, 0.5f, R, G, B );
}

void SvgAddLineFromToIndex( String * SVG, float y1, float y2, int indx_from, int indx_to, float size, float sizeY, float marginX, float marginY, float opacity, int id ){
  
  float e = 0.15;
  float x = 0.5;
  float x1 = ((size * indx_from) + ( size * x ) + marginX) + e;
  float x2 = ((size * indx_to  ) + ( size * x ) + marginX) + e;
  //float y1 = 0.2f;
  //float y2 = 0.8f;
  float t1, t2;
  
  t1 = (marginY + sizeY) - (sizeY * y1);
  t2 = (marginY + sizeY) - (sizeY * y2);
  
  sprintfSVGLineBtwSized( SVG, x1, t1, x2, t2, "black", 1.5f, opacity, id );
}


void SvgAddLineArray( String * svg , LineArray * lines,  float sizeX, float sizeY, float marginX, float marginY, float opacity ){
  
    int i;
    int L1;
    float y1, y2;
    int index1, index2;
    for( i = 0 ; i < L1 + 1; i++ ){
        y1 = lines->y1[i];
        y2 = lines->y2[i];
        index1 = i;
        index2 = i + 1;
        SvgAddLineFromToIndex( svg, y1, y2, index1, index2, sizeX, sizeY, marginX, marginY, opacity, i ); 
    }
  
}
  
void SvgAddRectOpacityIndex( String * SVG, float y1, float y2, float size, float sizeY, float marginX, float marginY, int index, int R, int G, int B, float opacity ){
  float x, SPC, SZ, t1;
  int i = index;
  float e = 0.15;
  x = (((size ) * i) + marginX) + e;
  SPC = size - (e*2);
  SZ = sizeY * (y2 - y1);
  t1 = (marginY + sizeY) - ((y1) * sizeY) - SZ;
  SvgAddRectRBG( SVG , x, t1, SPC, SZ, opacity, R, G, B );
}

void SvgAddPointIndex( String * SVG, float x0, float y0, float size, float sizeY, float marginX, float marginY, int index, int R, int G, int B){
  int i;
  float bot, SPC, SZ, t1;
  float x, y;
  int point_id = 0;
  x = marginX + (index * size) + (size * x0);
  y = marginY + sizeY - (( y0 ) * sizeY);
  sprintfSVGPointRGBRadius( SVG, x, y, R, G, B, 6, point_id );
} 

void SvgLabelColocatedEvens( String * svg, LineArray * lines, String * bufferS ){
  float x, y;
  char num[10];
  initCharArr( num, 10 );
  int i;
  for(i = 1 ; i < lines->length; i+=2 ){
    x = lines->x1[i] - .5;
    y = lines->y2[i] - .2;
    StringReset( bufferS );
    StringAppendChar( bufferS, 'X');
    gcvt(i+1, 2, num);
    StringAppendString2( bufferS, num  );
    sprintfSVGText( svg, x, y, bufferS->get );
  }
}

void SvgLabelColocatedOdds( String * svg, LineArray * lines , String * bufferS ){
  float x, y;
  char num[10];
  initCharArr( num, 10 );
  int i;
  for(i = 0 ; i < lines->length; i+=2 ){
    x = lines->x2[i] - 0.5;
    y = lines->y1[i] + 1.7;
    StringReset( bufferS );
    StringAppendChar( bufferS, 'X');
    gcvt(i+1, 2, num);
    StringAppendString2( bufferS, num  );
    sprintfSVGText( svg, x, y, bufferS->get  );
  }
  
}

void SvgLabelColocatedDimensions( String * svg, LineArray * lines , String * bufferS  ){
  SvgLabelColocatedEvens( svg,  lines,  bufferS );
  SvgLabelColocatedOdds( svg,   lines,  bufferS );
}

void SvgLabelColocatedRepeat( String * svg, LineArray * lines, char * d1, char * d2   ){
  float x, y;
  char * text;
  int i;
  for(i = 0 ; i < lines->length; i+=2 ){
    x = lines->x2[i] - 0.5;
    y = lines->y1[i] + 1.7;
    text = d1;
    sprintfSVGText( svg, x, y, text );
  }
  
  for(i = 1 ; i < lines->length; i+=2 ){
    x = lines->x1[i] - .5;
    y = lines->y2[i] - .2;
    text = d2;
    sprintfSVGText( svg, x, y, text );
  }
  
}

void sprintfSVGPointRGBRadius( String *  string, float x1, float y1, float R, float G, float B, float radius, int pointid   ){
  float opacity = 0.6;
  char save[50];
  
  initCharArr( save, 50 ); sprintf(save, "%s", "<circle " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "id" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "point-" );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%i", pointid ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "cx" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", x1 );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "cy" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", y1 );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "r" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", radius ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "stroke" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "black"  ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  
  initCharArr( save, 50 ); sprintf (save, "%s", "stroke-width" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", 0.1 );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  
  initCharArr( save, 50 ); sprintf (save, "%s", "opacity" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", opacity );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  
  initCharArr( save, 50 ); sprintf (save, "%s", "fill" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "rgb(" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.0f", R );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "," );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.0f", G ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "," );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.0f", B );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", ")" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " ); StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "/>" );  StringAppendString2( string , save ); 
  
}

void sprintfSVGRect(  String *  string , char * stem,  int i , float x, float y, float w, float h, float opacity, char * color  ){
  float strokeWidth = 0;
  char save[50];
  
  initCharArr( save, 50 ); sprintf (save, "%s", "<rect " ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "id" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" ); StringAppendString2( string , save );  
  initCharArr( save, 50 ); sprintf (save, "%s", stem ); StringAppendString2( string , save );  
  initCharArr( save, 50 ); sprintf (save, "%i", i );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "x" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", x );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "y" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", y );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "width" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", w );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "height" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", h );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "opacity" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", opacity );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "fill" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", color  ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  //sprintf (save, "%s","style=\"" );StringAppendString2( string , save ); 
  //sprintf (save, "%s","display:none;" );StringAppendString2( string , save ); 
  //sprintf (save, "%s", "\"" );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "/>" );  StringAppendString2( string , save ); 
  
}



void sprintfSVGRectRBG(  String *  string , char * stem,  int i , float x, float y, float w, float h, float opacity, int R, int G, int B ){
  float strokeWidth = 0;
  char save[50];
  
  initCharArr( save, 50 ); sprintf (save, "%s", "<rect " ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "id" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" ); StringAppendString2( string , save );  
  initCharArr( save, 50 ); sprintf (save, "%s", stem ); StringAppendString2( string , save );  
  initCharArr( save, 50 ); sprintf (save, "%i", i );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "x" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", x );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "y" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", y );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "width" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", w );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "height" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", h );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "%s", "opacity" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%.2f", opacity );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( string , save ); 
  
  
  initCharArr( save, 50 ); sprintf (save, "%s", "fill" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "rgb(" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%i", R );  StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "," );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%i", G ); StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "," );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%i", B );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", ")" );StringAppendString2( string , save ); 
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " ); StringAppendString2( string , save ); 
  
  //sprintf (save, "%s","style=\"" );StringAppendString2( string , save ); 
  //sprintf (save, "%s","display:none;" );StringAppendString2( string , save ); 
  //sprintf (save, "%s", "\"" );StringAppendString2( string , save ); 
  
  initCharArr( save, 50 ); sprintf (save, "/>" );  StringAppendString2( string , save ); 
  
}
void SvgAddRectRBG( String * SVG, float x, float y, float w, float h, float opacity, int R, int G, int B ){
  int i;
  int index;
  String * cls;
  sprintfSVGRectRBG( SVG, "stem", i, x, y, w, h  ,opacity , R, G, B);
}
void SvgAddRect( String * SVG, FloatArray * floats  , float opacity, char * color ){
  int i;
  int index;
  String * cls;
  int R, G, B; 
  float x, y, w, h;
  for( i = 0 ; i < floats->length ; i+=4 ){
    x = floats->get[i + 0]; 
    y = floats->get[i + 1]; 
    w = floats->get[i + 2]; 
    h = floats->get[i + 3]; 
    sprintfSVGRect( SVG, "stem", i, x, y, w, h  ,opacity , color);
  }
}


void SvgAddHyperRect( String * SVG, FloatArray * CLASS, FloatArray * bufferFA, char * color, float size, float sizeY, float marginX, float marginY ){
  int i;
  float x, y;
  float bot, SPC, SZ, t1;
  for( i = 0 ; i < CLASS->length / 2; i++ ){
    x = (size * i) + marginX;
    SPC = (1 - CLASS->get[ i * 2 + 1]) * sizeY;
    SZ = sizeY * (CLASS->get[ i * 2 + 1 ] - CLASS->get[ i * 2 + 0 ]);
    t1 = (marginY + sizeY) - ((CLASS->get[ i * 2 + 0]) * sizeY) - SZ;
    FloatArrayAdd( bufferFA , x ); 
    FloatArrayAdd( bufferFA , t1 ); 
    FloatArrayAdd( bufferFA , size + 0.01f ); 
    FloatArrayAdd( bufferFA , SZ );
  }
  SvgAddRect( SVG, bufferFA , 0.5f, color );
}


void SvgAddHyperRectIndex( String * SVG, FloatArray * CLASS, FloatArray * bufferFA, char * color, float size, float sizeY, float marginX, float marginY, int index ){
  int i;
  float x, y;
  float bot, SPC, SZ, t1;
  FloatArrayReset( bufferFA ); 
  for( i = 0 ; i < CLASS->length / 2; i++ ){
    
    x = (size *  index ) + marginX;
    
    
    SPC = (1 - CLASS->get[ i * 2 + 1]) * sizeY;
    SZ = sizeY * (CLASS->get[ i * 2 + 1 ] - CLASS->get[ i * 2 + 0 ]);
    t1 = (marginY + sizeY) - ((CLASS->get[ i * 2 + 0]) * sizeY) - SZ;
    FloatArrayAdd( bufferFA , x ); 
    FloatArrayAdd( bufferFA , t1 ); 
    FloatArrayAdd( bufferFA , size + 0.01f ); 
    FloatArrayAdd( bufferFA , SZ ); 
  }
  SvgAddRect( SVG, bufferFA , 0.5f, color );
}


void SvgOpen( String *  save ){
  char buffer[200];
  initCharArr( buffer, 200 ); 
  sprintf (buffer, "%s", "<svg width=\"100%\" height=\"100%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">");
  StringAppendString2( save , buffer ); 
  //fprintf (save, "%s", "<svg viewBox=\"0 0 100% 100%\" xmlns=\"http://www.w3.org/2000/svg\">" );
}

void SvgClose( String *  save ){
  char buffer[20];
  initCharArr( buffer, 20 ); 
  sprintf (buffer, "%s",  "</svg>");
  StringAppendString2( save , buffer ); 
}


void SvgExport( String * SVG, String * filename_buffer, char * FULL_FILEPATH ){
  StringReset( filename_buffer ); 
  //StringAppendString2( filename_buffer, LOCATION );
  //StringAppendString2( filename_buffer, ROOT );
  //StringAppendString2( filename_buffer, WEBAPP );
  //StringAppendString2( filename_buffer, filename_stem ); 
  //StringAppendString2( filename_buffer, ".svg" ); 
  StringAppendString2( filename_buffer, FULL_FILEPATH ); 
  printf("SAVING SVG TO: %s(%i)\n", filename_buffer->get , length(filename_buffer->get) );
  
  FILE *  save = fopen ( filename_buffer->get , "w" );
  int i;
  for( i = 0 ; i < SVG->length; i++ ){
    fprintf (save, "%c",  SVG->get[i] );
  }
  
  fclose (save);
  
}



void SvgExport2( String * SVG,  char * FULL_FILEPATH ){
  
  FILE *  save = fopen ( FULL_FILEPATH , "w" );
  int i;
  for( i = 0 ; i < SVG->length; i++ ){
    fprintf (save, "%c",  SVG->get[i] );
  }
  
  fclose (save);
  
  
}

void sprintfSVGText( String *  str, float x, float y, char * text  ){
  int i = 0;
  char save[50];
  char * stem = "dimensions";
  char * font = "Verdana";
  float fontSize = 10;
  
  
  initCharArr( save, 50 ); sprintf (save, "%s", "<text " );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "id" );  StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" ); StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", stem );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%i", i );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, "%s", "x" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%.2f", x );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, "%s", "y" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%.2f", y );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "%" ); StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, "%s", "font-size" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%.2f", fontSize );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, "%s", "font-family" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "=\"" );StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", font );  StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", "\" " );StringAppendString2( str, save );
  
  //initCharArr( save, 50 ); sprintf (save, "%s","style=\"" );StringAppendString2( str, save );
  //initCharArr( save, 50 ); sprintf (save, "%s","display:none;" );StringAppendString2( str, save );
  //initCharArr( save, 50 ); sprintf (save, "%s", "\"" );StringAppendString2( str, save );
  
  initCharArr( save, 50 ); sprintf (save, ">" ); StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "%s", text ); StringAppendString2( str, save );
  initCharArr( save, 50 ); sprintf (save, "</text>" );  StringAppendString2( str, save );
  
  
  
  
  
}


void sprintfSVGLineBtwSized( String *  save, float x1, float y1, float x2, float y2, char * color  , float width, float opacity, int lineid ){
  //float opacity = 0.3f;
  char str[50];
  
  initCharArr( str, 50 ); sprintf (str, "%s", "<line " );   StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "id" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "grid-" );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%i", lineid ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "vector-effect" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "non-scaling-stroke" );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "x1" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", x1 );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "%" ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "y1" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", y1 );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "%" ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "x2" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", x2 );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "%" ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "y2" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", y2 );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "%" ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "stroke" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", color  ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "stroke-width" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", width );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "%" ); StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "%s", "stroke-opacity" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "=\"" );StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%.2f", opacity );  StringAppendString2( save, str );
  initCharArr( str, 50 ); sprintf (str, "%s", "\" " );StringAppendString2( save, str );
  
  initCharArr( str, 50 ); sprintf (str, "/>" );  StringAppendString2( save, str );
  
}

void SvgAddLines( String * SVG, LineArray * grid, char * color, float linewidth, float opacity ){
  int i;
  int index;
  String * class;
  int R, G, B; 
  float x1, y1, x2, y2;
  for( i = 0 ; i < grid->length ; i++ ){
    x1 = grid->x1[i]; 
    y1 = grid->y1[i];
    x2 = grid->x2[i]; 
    y2 = grid->y2[i];
    sprintfSVGLineBtwSized( SVG, x1, y1, x2, y2, color, linewidth, opacity, i );
  }
}
#endif // STRUCTURESSVG_H_