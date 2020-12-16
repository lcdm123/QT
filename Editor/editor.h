#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTextCharFormat>

class QLineEdit;
class QDialog;


namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);

public:
    void newFile();  //新建文档

    bool maybeSave(); // 判断是否需要保存

    bool save(); // 保存

    bool saveAs(); //另存为

    bool saveFile(const QString &fileName); //保存文件

    bool loadFile(const QString &fileName); // 打开文件

    void mergeFormat(QTextCharFormat fmt); // 光标

    explicit Editor(QWidget *parent = 0);
    ~Editor();

private slots:
    void on_New_triggered();

    void on_Save_triggered();

    void on_Save_other_triggered();


    void on_Open_triggered();

    void on_Close_triggered();

    void on_Exit_triggered();

    void on_Undo_triggered();

    void on_Cut_triggered();

    void on_Copy_triggered();

    void on_Past_triggered();

    void showFindText(); //查找

    void on_Find_triggered();

    void on_jiachu_triggered();

    void on_qingxie_triggered();

    void on_xiahuaxain_triggered();

    void on_ziti_triggered();

    void on_left_triggered();

    void on_right_triggered();

    void on_center_triggered();

private:
    bool isUntitled; //判断文件是否保存过

    QString curFile; //保存当前文件的路径

    // 查找
    QLineEdit *findLineEdit;

    QDialog *findDlg;

    Ui::Editor *ui;
};

#endif // EDITOR_H

#-------------------------------------------------
#
# Project created by QtCreator 2020-12-11T23:09:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        editor.cpp

HEADERS += \
        editor.h

FORMS += \
        editor.ui

<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>Editor</class>
 <widget class="QMainWindow" name="Editor">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>1357</width>
    <height>1034</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Editor</string>
  </property>
  <widget class="QWidget" name="centralWidget">
   <layout class="QGridLayout" name="gridLayout_2">
    <item row="1" column="0" colspan="2">
     <layout class="QGridLayout" name="gridLayout">
      <item row="1" column="0">
       <widget class="QTextEdit" name="textEdit"/>
      </item>
     </layout>
    </item>
   </layout>
  </widget>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>1357</width>
     <height>26</height>
    </rect>
   </property>
   <widget class="QMenu" name="menu">
    <property name="title">
     <string>文件(&amp;F)</string>
    </property>
    <addaction name="New"/>
    <addaction name="Open"/>
    <addaction name="Close"/>
    <addaction name="Save"/>
    <addaction name="Save_other"/>
    <addaction name="Exit"/>
   </widget>
   <widget class="QMenu" name="menu_2">
    <property name="title">
     <string>编辑</string>
    </property>
    <addaction name="Undo"/>
    <addaction name="Cut"/>
    <addaction name="Copy"/>
    <addaction name="Past"/>
    <addaction name="Find"/>
   </widget>
   <widget class="QMenu" name="menu_3">
    <property name="title">
     <string>工具</string>
    </property>
    <addaction name="jiachu"/>
    <addaction name="xiahuaxain"/>
    <addaction name="qingxie"/>
    <addaction name="ziti"/>
    <addaction name="left"/>
    <addaction name="right"/>
    <addaction name="center"/>
   </widget>
   <addaction name="menu"/>
   <addaction name="menu_2"/>
   <addaction name="menu_3"/>
  </widget>
  <widget class="QStatusBar" name="statusBar"/>
  <widget class="QToolBar" name="toolBar">
   <property name="windowTitle">
    <string>toolBar</string>
   </property>
   <property name="iconSize">
    <size>
     <width>5000</width>
     <height>30</height>
    </size>
   </property>
   <attribute name="toolBarArea">
    <enum>TopToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
   <addaction name="New"/>
   <addaction name="Open"/>
   <addaction name="Save"/>
   <addaction name="Save_other"/>
   <addaction name="Find"/>
   <addaction name="separator"/>
   <addaction name="ziti"/>
   <addaction name="jiachu"/>
   <addaction name="xiahuaxain"/>
   <addaction name="qingxie"/>
   <addaction name="left"/>
   <addaction name="right"/>
   <addaction name="center"/>
  </widget>
  <action name="Undo">
   <property name="text">
    <string>撤销(&amp;z)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+Z</string>
   </property>
  </action>
  <action name="Cut">
   <property name="text">
    <string>剪切(&amp;x)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+X</string>
   </property>
  </action>
  <action name="New">
   <property name="text">
    <string>新建(&amp;N)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+N</string>
   </property>
  </action>
  <action name="Open">
   <property name="text">
    <string>打开(&amp;O)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+O</string>
   </property>
  </action>
  <action name="Close">
   <property name="text">
    <string>关闭(&amp;C)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+W</string>
   </property>
  </action>
  <action name="Save">
   <property name="text">
    <string>保存(&amp;S)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+S</string>
   </property>
  </action>
  <action name="Save_other">
   <property name="text">
    <string>另存为(&amp;A)</string>
   </property>
  </action>
  <action name="Exit">
   <property name="text">
    <string>退出(&amp;Q)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+Q</string>
   </property>
  </action>
  <action name="Copy">
   <property name="text">
    <string>复制(&amp;c)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+C</string>
   </property>
  </action>
  <action name="Past">
   <property name="text">
    <string>粘贴(&amp;v)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+V</string>
   </property>
  </action>
  <action name="Find">
   <property name="text">
    <string>查找(&amp;F)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+F</string>
   </property>
  </action>
  <action name="jiachu">
   <property name="text">
    <string>加粗</string>
   </property>
  </action>
  <action name="xiahuaxain">
   <property name="text">
    <string>下划线</string>
   </property>
  </action>
  <action name="qingxie">
   <property name="text">
    <string>倾斜</string>
   </property>
  </action>
  <action name="ziti">
   <property name="text">
    <string>字体</string>
   </property>
  </action>
  <action name="left">
   <property name="text">
    <string>左对齐</string>
   </property>
  </action>
  <action name="right">
   <property name="text">
    <string>右对齐</string>
   </property>
  </action>
  <action name="center">
   <property name="text">
    <string>居中</string>
   </property>
  </action>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources/>
 <connections/>
</ui>

#include "editor.h"
#include "ui_editor.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QTextCharFormat>
#include <QFont>
#include <QFontDialog>

bool boldcheck=true;
bool Italiccheck=true;
bool UnderLinecheck=true;

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::Editor)
{
    ui->setupUi(this);

    isUntitled = true;

    curFile = tr("未命名.txt");

    setWindowTitle(curFile);

    // 查找功能
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton *btn= new QPushButton(tr("查找下一个"), findDlg);
    QVBoxLayout *layout= new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));
}


Editor::~Editor()
{
    delete ui;
}



// 新建文件

void Editor::newFile()
{
   if (maybeSave()) {
       isUntitled = true;
       curFile = tr("未命名.txt");
       setWindowTitle(curFile);
       ui->textEdit->clear();
       ui->textEdit->setVisible(true);
   }
}


bool Editor::maybeSave()
{
    // 如果文档被更改了
    if (ui->textEdit->document()->isModified()) {
    // 自定义一个警告对话框
       QMessageBox box;
       box.setWindowTitle(tr("警告"));
       box.setIcon(QMessageBox::Warning);
       box.setText(curFile + tr(" 尚未保存，是否保存？"));
       QPushButton *yesBtn = box.addButton(tr("是(&Y)"),
                        QMessageBox::YesRole);
       box.addButton(tr("否(&N)"), QMessageBox::NoRole);
       QPushButton *cancelBut = box.addButton(tr("取消"),
                        QMessageBox::RejectRole);
       box.exec();
       if (box.clickedButton() == yesBtn)
            return save();
       else if (box.clickedButton() == cancelBut)
            return false;
   }

    // 如果文档没有被更改，则直接返回true

   return true;
}

//保存文件

bool Editor::save()
{
   if (isUntitled) {
       return saveAs();
   } else {
       return saveFile(curFile);
   }
}

//另存为

bool Editor::saveAs()
{
   QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
   if (fileName.isEmpty()) return false;
   return saveFile(fileName);
}

//  文件保存路径
bool Editor::saveFile(const QString &fileName)
{
   QFile file(fileName);

   if (!file.open(QFile::WriteOnly | QFile::Text)) {

       // %1和%2分别对应后面arg两个参数，/n起换行的作用
       QMessageBox::warning(this, tr("多文档编辑器"),
                   tr("无法写入文件 %1：/n %2")
                  .arg(fileName).arg(file.errorString()));
       return false;
   }
   QTextStream out(&file);
   // 鼠标指针变为等待状态
   QApplication::setOverrideCursor(Qt::WaitCursor);
   out << ui->textEdit->toPlainText();
   // 鼠标指针恢复原来的状态
   QApplication::restoreOverrideCursor();
   isUntitled = false;
   // 获得文件的标准路径
   curFile = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(curFile);
   return true;
}

// 打开文件
bool Editor::loadFile(const QString &fileName)
{
   QFile file(fileName); // 新建QFile对象
   if (!file.open(QFile::ReadOnly | QFile::Text)) {
       QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
       return false; // 只读方式打开文件，出错则提示，并返回false
   }
   QTextStream in(&file); // 新建文本流对象
   QApplication::setOverrideCursor(Qt::WaitCursor);
   // 读取文件的全部文本内容，并添加到编辑器中
   ui->textEdit->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();

   // 设置当前文件
   curFile = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(curFile);
   return true;
}

void Editor::closeEvent(QCloseEvent *event)
{
   // 如果maybeSave()函数返回true，则关闭程序
   if (maybeSave()) {
       event->accept();
   } else {   // 否则忽略该事件
       event->ignore();
   }
}

// 查找
void Editor::showFindText()
{
   QString str = findLineEdit->text();
   if (!ui->textEdit->find(str, QTextDocument::FindBackward))
   {
      QMessageBox::warning(this, tr("查找"),
               tr("找不到%1").arg(str));
   }

}


 //新建
void Editor::on_New_triggered()
{
    newFile();
}

//保存
void Editor::on_Save_triggered()
{
    save();
}
// 另存为
void Editor::on_Save_other_triggered()
{
    saveAs();
}

// 打开
void Editor::on_Open_triggered()
{
    if (maybeSave()) {

          QString fileName = QFileDialog::getOpenFileName(this);

          // 如果文件名不为空，则加载文件
          if (!fileName.isEmpty()) {
               loadFile(fileName);
               ui->textEdit->setVisible(true);
          }
      }
}


void Editor::on_Close_triggered()
{
    if (maybeSave()) {
           //ui->textEdit->setVisible(false);
        ui->textEdit->clear();
       }
}

void Editor::on_Exit_triggered()
{
    // 先执行关闭操作，再退出程序
      // qApp是指向应用程序的全局指针
      on_Close_triggered();
      qApp->quit();
}



void Editor::on_Undo_triggered()
{
    ui->textEdit->undo();
}

void Editor::on_Cut_triggered()
{
    ui->textEdit->cut();
}


void Editor::on_Copy_triggered()
{
    ui->textEdit->copy();
}


void Editor::on_Past_triggered()
{
    ui->textEdit->paste();
}

void Editor::on_Find_triggered()
{
    findDlg->show();
}

// 光标选中

void Editor::mergeFormat(QTextCharFormat fmt)
{
QTextCursor cursor = ui->textEdit->textCursor();
if (!cursor.hasSelection()) {
cursor.select(QTextCursor::WordUnderCursor);
}
cursor.mergeCharFormat(fmt);
}

// 加粗
void Editor::on_jiachu_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldcheck ? 75: 50);
    mergeFormat(fmt);
    boldcheck = !boldcheck;
}

 // 倾斜

void Editor::on_qingxie_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(Italiccheck ? true : false);
    mergeFormat(fmt);
    Italiccheck = !Italiccheck;
}

// 下划线


void Editor::on_xiahuaxain_triggered()
{
    QTextCharFormat fmt;
       fmt.setFontUnderline(UnderLinecheck ? true : false);
       mergeFormat(fmt);
       UnderLinecheck = !UnderLinecheck;
}





void Editor::on_ziti_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("楷体", 20), this);

    if(ok){
        ui->textEdit->setCurrentFont(font);
    }
}

// 左对齐
void Editor::on_left_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

// 右对齐
void Editor::on_right_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

// 居中对齐
void Editor::on_center_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
