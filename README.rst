==========================================
zentropy, Measure entropy of parts of file
==========================================

Usage
-----

::

    $ qmake zentropy.pro
    $ make
    $ ./zentropy file 1000

Output line:
 120000 130000 10000 5284 52.84 0001000100010001000100010001000100000000

Columns description:
 * 120000 - 130000 - bytes of input file
 * 10000 - length of current piece
 * 5284 - length of compressed (zlib with default compression level is used)
 * 52.84 = 5284 / 10000 * 100 - compression ratio
 * 0001000100010001000100010001000100000000 - first 20 bytes of piece

Links
-----

 * http://habrahabr.ru/post/180803/

----

Boris Nagaev <bnagaev@gmail.com>

