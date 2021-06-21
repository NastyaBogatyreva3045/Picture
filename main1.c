# включить  < stdio.h >
# включить  < stdlib.h >
# включить  < string.h >

int  main ( int ac, char * av [])
{
   char * nameFile;
   если (ac> 1 ) nameFile = av [ 1 ];
   еще
  {
    printf ( " Имя файла не указано " );
    возврат  1 ;
  }
    ФАЙЛ * fIn = fopen (nameFile, « rb » );
    ФАЙЛ * fOut = fopen ( " newpicture.bmp " , " wb " );
    если (! fIn ||! fOut)
    {
        printf ( " Ошибка файла. \ n " );
        возврат  0 ;
    }

     заголовок беззнакового символа [ 54 ];
    fread (заголовок, sizeof ( символ без знака  ), 54 , fIn);
    fwrite (заголовок, sizeof ( символ без знака  ), 54 , fOut);

    int width = * ( int *) и заголовок [ 18 ];
    int height = abs (* ( int *) и заголовок [ 22 ]);
    int stride = (ширина * 3 + 3 ) & ~ 3 ;
    int padding = stride - ширина * 3 ;

    printf ( « Готово! » );

    беззнаковый  символ пикселя [ 3 ];
    для ( int y = 0 ; y <height; ++ y)
    {
        для ( int x = 0 ; x <width; ++ x)
        {
            fread (пиксель, 3 , 1 , fIn);
             серый символ без знака = пиксель [ 0 ] * 0,3 + пиксель [ 1 ] * 0,58 + пиксель [ 2 ] * 0,11 ;
            memset (пиксель, серый, размер (пиксель));
            fwrite (& pixel, 3 , 1 , fOut);
        }
        fread (пиксель, отступ, 1 , fIn);
        fwrite (пиксель, отступ, 1 , fOut);
    }
    fclose (fOut);
    fclose (fIn);
    возврат  0 ;
}