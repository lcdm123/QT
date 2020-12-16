#ifndef JSQ_H
#define JSQ_H

#include <QDialog>
#include <QStack>

namespace Ui {
class JSQ;
}

class JSQ : public QDialog
{
    Q_OBJECT

public:
    explicit JSQ(QWidget *parent = 0);
    ~JSQ();

    int process(char a,char b);  //  优先级比较

    QString calculate();  // 计算值

private slots:

    void on_num_0_clicked();

    void on_num_1_clicked();

    void on_num_2_clicked();

    void on_num_3_clicked();

    void on_num_4_clicked();

    void on_num_5_clicked();

    void on_num_6_clicked();

    void on_num_7_clicked();

    void on_num_8_clicked();

    void on_num_9_clicked();

    void on_btn_xsd_clicked();  //   小数点

    void on_btn_lkuohao_clicked(); // （

    void on_btn_rkuohao_clicked(); //  ）

    void on_btn_c_clicked(); //      清除

    void on_btn_jia_clicked();  //   +

    void on_btn_jian_clicked(); //   -

    void on_btn_cheng_clicked(); //  *

    void on_btn_chu_clicked(); //    /

    void on_btn_tuige_clicked(); //  back

   // void on_btn_lg_clicked();  //   lg

   // void on_btn_daoshu_clicked(); //  倒数

    void on_btn_jiecheng_clicked();// 阶乘

    void on_btn_genghao_clicked(); // 根号

    void on_pushButton_clicked();

    void on_btn_d_clicked();


private:
    Ui::JSQ *ui;
    QString tmp;
};

#endif // JSQ_H
