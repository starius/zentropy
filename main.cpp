#include <cstdio>
#include <QtCore>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: zentropy file piece_size\n");
        return 1;
    }
    QString filename = argv[1];
    const qint64 PIECE_SIZE = QString(argv[2]).toInt();
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return 2;
    }
    int piece_index = 0;
    while (!file.atEnd()) {
        QByteArray piece = file.read(PIECE_SIZE);
        qint64 piece_size = piece.size();
        QByteArray compressed = qCompress(piece);
        qint64 compressed_size = compressed.size();
        double rate = double(compressed_size) / double(piece_size);
        double percent = rate * 100.0;
        qint64 begin_byte = piece_index * PIECE_SIZE;
        qint64 end_byte = begin_byte + piece_size;
        printf("%lld\t%lld\t%lld\t%lld\t%.02f\t%s\n",
               begin_byte, end_byte,
               piece_size, compressed_size, percent,
               piece.left(20).toHex().constData());
        piece_index += 1;
    }
}
