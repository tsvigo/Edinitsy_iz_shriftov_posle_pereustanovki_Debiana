#include "dialog.h"
#include "ui_dialog.h"

#include <QColor>
#include <QFile>
#include <QTextStream>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <QProcess>
#include <QFileDialog>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
#include <QDebug>

#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QFileInfoList>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
QString h,w,s;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
QString  Nazvaniye_fayla_s_neyronami_i_signalom ;
QString  Nazvaniye_fayla_s_bmp;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// 
void findNewestFile(const QString& searchPath, const QString& fileName) {
    QDir dir(searchPath);
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
// Fraction f;
//f.getNumerator();
    QFileInfoList list= //=
   // list.ent
     QDir::entryInfoList
     ("/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/"
     ,
      QDir::DirsFirst | QDir::Time
      );

    for (const QFileInfo& fileInfo : list) {
        if (fileInfo.isDir()) {
            findNewestFile(fileInfo.filePath(), fileName);
        } else if (fileInfo.fileName() == fileName) {
            qDebug() << "Newest file with name" << fileName << "is:" << fileInfo.filePath();
            return;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// // 
Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);

// Открываем файл с путями
QFile file("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/image_paths.txt");
if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Не удалось открыть файл с путями.";
    return;
}

// Читаем пути файлов из файла в цикле for
QTextStream in(&file);
while (!in.atEnd())
 {
    QString line = in.readLine();
    qDebug() << "Путь к файлу:" << line;
// здесь код
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// считывание картинки
  ui->textEdit->clear();
Nazvaniye_fayla_s_bmp =  line;
  QImage img(

      Nazvaniye_fayla_s_bmp.toStdString().c_str()
      //NOTE: файл изображения bmp
      
             ); // входящий файл изображения  
  h = QString::number(img.height());

  w = QString::number(img.width());


  int kolichestvo = img.height() * img.width();
  s = QString::number(kolichestvo);

 // int z;
  for (int x = 0; x < img.width(); x++)
    for (int y = 0; y < img.height(); y++)
      ui->textEdit->append(QString::number(img.pixel(x, y)));

  // Заполнили текстовое первое поле   

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///   
// Open последний текущий файл с нейронами и сигналами txt 
// найти самый свежий файл с именем neurons_and_signal.txt в папке и во вложенных папках

        
     
 } // цикл

file.close(); // Закрываем файл после чтения

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
 //findNewestFile("/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/", "neurons_and_signal.txt") ; 
//   QString path = "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/";
//    QDir dir(path);

//    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot);
//    QFileInfo latestFile;

//    foreach (const QFileInfo &fileInfo, fileInfoList) {
//        if (!latestFile.exists() || fileInfo.lastModified() > latestFile.lastModified()) {
//            latestFile = fileInfo;
//        }
//    }

//    if (latestFile.exists()) {
//        qDebug() << "The most recent file is:" << latestFile.absoluteFilePath();
//    } else {
//        qDebug() << "No files found in the directory.";
//    }

}

Dialog::~Dialog() { delete ui; }

// считываем картинку:
void Dialog::on_pushButton_clicked() {
  ui->textEdit->clear();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///     
    Nazvaniye_fayla_s_bmp = QFileDialog::getOpenFileName(this,
  tr("Open bmp"), "/home/viktor/Изображения/edinitsi/", tr("Txt Files (*.bmp)"));
  ui->label->setText (Nazvaniye_fayla_s_bmp);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief img
  /// \return 
  ///  
  QImage img(

      Nazvaniye_fayla_s_bmp.toStdString().c_str()
      //NOTE: файл изображения bmp
      
             ); // входящий файл изображения


  h = QString::number(img.height());

  w = QString::number(img.width());


  int kolichestvo = img.height() * img.width();
  s = QString::number(kolichestvo);

 // int z;
  for (int x = 0; x < img.width(); x++)
    for (int y = 0; y < img.height(); y++)
      ui->textEdit->append(QString::number(img.pixel(x, y)));

  // Заполнили текстовое первое поле
   QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::on_pushButton_2_clicked
///
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// кнопка Записать в файл
void Dialog::on_pushButton_2_clicked() {
//    QPushButton *openFileNameButton =
//        new QPushButton(tr("QFileDialog::get&OpenFileName()"));
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
//QFileDialog::ExistingFile
QFileDialog dialog(this);
dialog.setFileMode(QFileDialog::ExistingFile);
      Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
 tr("Open последний текущий файл с нейронами и сигналами txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
//dialog.
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///      
  // ui->textEdit->clear();
  //  QFile file("/home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/"
  //             "out.txt"); // выходной файл
  //  // /home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/1.bmp
  //  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
  //    return;

  //  QTextStream out(&file); //поток для записи текста
  //  out << ui->textEdit->toPlainText(); // записали картинку в out.txt

  //  file.close();
  // тут пишет в файл out.txt а надо это записать это в первые 100 нейронов
  /// Тут надо добавить нейроны со 101 по 201 из
  ///  /home/viktor/my_projects_qt_2/build-zapolnenie_nejronov_sluchajnymi_nachalnymi_zaryadami_4-Desktop_Qt_5_12_12_GCC_64bit-Debug/neyroni.txt
  ///
  QFile file_n(
//      "/home/viktor/my_projects_qt_2/"
//               "build-zapolnenie_nejronov_sluchajnymi_nachalnymi_zaryadami_4-"
//               "Desktop_Qt_5_12_12_GCC_64bit-Debug/neyroni.txt"
      
  //    "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1/neyroni.txt"
      
    //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0/neyroni.txt"
    //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1/neurons_and_signal-2.txt"
    //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt"
   // "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1(2)/neyroni_i_signal.txt"
        Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
      // тут надо на уже сделанный прочитать
      
      //NOTE: файл neyroni.txt
      
      );
  // заряды нейронов
  if (!file_n.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
  for (int var = 1; var < 202; ++var) { // 204
    ui->textEdit_2->append(
        file_n.readLine()
            .simplified()); // во второе текстовое поле вывели все нейроны
  }

  // теперь в конец первого текстового поля добавим из второго
  QString str = ui->textEdit_2->toPlainText();
  QStringList strList =
      str.split('\n'); // разбиваем строку из текстедита на отдельные строки

  for (int var = 100; var < 201; ++var) { // 202

    str = strList.at(var); // берем строку
    ui->textEdit->append(str);
    // ui->textEdit->append(file_n.readLine(var).simplified());
    //  file.readLine().simplified()
  }
  file_n.close();
  /// тут надо записать обновлённый файл neyroni.txt с сигналами-рисунком
  ///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
 tr("Куда записать файл с нейронами и сигналами txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  
  QFile file3(
//      "/home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/"
//              "neyroni_i_signal.txt"
      
   //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1/neyroni_i_signal.txt"
      
   //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0/neyroni_i_signal.txt"
    //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1(2)/neyroni_i_signal.txt"
      // "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt"
       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
      // перезаписался /home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt с сигналом 1-2
      // а надо выбрать куда его сохранить
      // перезаписать с новым сигналом
      //NOTE: файл neyroni_i_signal.txt
      
      ); // выходной файл
  if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
  QTextStream out3(&file3); //поток для записи текста
  out3 << ui->textEdit
              ->toPlainText(); // записали картинку в neyroni_i_signal.txt

  file3.close();
   QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
}
