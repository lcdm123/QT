#include "jsq.h"
#include "floatnumber.h" //结构体
#include "ui_jsq.h"
#include "QString"
#include "qmath.h"
//#include<QDebug>


typedef struct node _tNode;
#define NUM_OF_NUMBER 20
#define KIND_NUMBER 0
#define KIND_OPERATOR 1

JSQ::JSQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JSQ)
{
    ui->setupUi(this);
   // this->tmp;
}

JSQ::~JSQ()
{
    delete ui;
}

void JSQ::on_num_0_clicked()
{
    QString str_0=ui->lineEdit->text();
    ui->lineEdit->setText(str_0+"0");
}

void JSQ::on_num_1_clicked()
{
    QString str_1 = ui->lineEdit->text();
    ui->lineEdit->setText(str_1+"1");
}

void JSQ::on_num_2_clicked()
{
    QString str_2 = ui->lineEdit->text();
    ui->lineEdit->setText(str_2+"2");
}

void JSQ::on_num_3_clicked()
{
    QString str_3 = ui->lineEdit->text();
    ui->lineEdit->setText(str_3+"3");
}

void JSQ::on_num_4_clicked()
{
    QString str_4 = ui->lineEdit->text();
    ui->lineEdit->setText(str_4+"4");
}

void JSQ::on_num_5_clicked()
{
    QString str_5 = ui->lineEdit->text();
    ui->lineEdit->setText(str_5+"5");
}

void JSQ::on_num_6_clicked()
{
    QString str_6 = ui->lineEdit->text();
    ui->lineEdit->setText(str_6+"6");
}

void JSQ::on_num_7_clicked()
{
    QString str_7 = ui->lineEdit->text();
    ui->lineEdit->setText(str_7+"7");
}

void JSQ::on_num_8_clicked()
{
    QString str_8 = ui->lineEdit->text();
    ui->lineEdit->setText(str_8+"8");
}

void JSQ::on_num_9_clicked()
{
    QString str_9=ui->lineEdit->text();
    ui->lineEdit->setText(str_9+"9");
}

void JSQ::on_btn_xsd_clicked() //小数点
{
    QString str_dian = ui->lineEdit->text();
    QString str = str_dian.mid(str_dian.length()-1,1);
    if(str=="." || str=="+" || str=="-"|| str=="*" || str=="/" || str=="(" || str==")"){
    ui->lineEdit->setText("ERROR");
    }else
    {
    ui->lineEdit->setText(str_dian+".");
    }
}

void JSQ::on_btn_lkuohao_clicked() // (
{
    QString str_lkuohao=ui->lineEdit->text();
    QString str = str_lkuohao.mid(str_lkuohao.length()-1,1);
    if(str=="."||str==")" || str=="0"|| str=="1"|| str=="2"|| str=="3"|| str=="4"|| str=="5"|| str=="6"|| str=="7"|| str=="8"|| str=="9"){
    ui->lineEdit->setText("ERROR");
    }else
    {
    ui->lineEdit->setText(str_lkuohao+"(");
    }
}

void JSQ::on_btn_rkuohao_clicked() //  ）
{
    QString str_rkuohao=ui->lineEdit->text();
    QString str = str_rkuohao.mid(str_rkuohao.length()-1,1);
    QString str_1 = str_rkuohao.mid(str_rkuohao.length()-2,1);

    if(str=="." || str=="+" || str=="-"|| str=="*" || str=="/" || str_1=="/0"){
    ui->lineEdit->setText("ERROR");
    }else if(str=="("){
        if(str_rkuohao.mid(str_rkuohao.length()-3,3)=="lg("){
            str_rkuohao=str_rkuohao.mid(0,str_rkuohao.length()-3);
            ui->lineEdit->setText(str_rkuohao);
        }
        else{
         str_rkuohao=str_rkuohao.mid(0,str_rkuohao.length()-1);
         ui->lineEdit->setText(str_rkuohao);
        }
    }
    else
    {
    ui->lineEdit->setText(str_rkuohao+")");
    }
}

void JSQ::on_btn_c_clicked()  //清除
{
    ui->lineEdit->clear();
}

void JSQ::on_btn_jia_clicked()  //  +
{
    QString str_jia = ui->lineEdit->text();
    QString str=str_jia.mid(str_jia.length()-1,1);
    QString str_1=str_jia.mid(str_jia.length()-2,2);
    if(str=="+" || str=="-" || str=="*"|| str=="/"|| str=="(" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_jia+"+");
    }
}

void JSQ::on_btn_jian_clicked()  // 减
{
    QString str_jian=ui->lineEdit->text();
    QString str=str_jian.mid(str_jian.length()-1,1);
    QString str_1=str_jian.mid(str_jian.length()-2,2);
    if(str=="+" || str=="-" || str=="*"|| str=="/" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_jian+"-");
    }
}

void JSQ::on_btn_cheng_clicked() // *
{
    QString str_cheng=ui->lineEdit->text();
    QString str=str_cheng.mid(str_cheng.length()-1,1);
    QString str_1=str_cheng.mid(str_cheng.length()-2,2);
    if(str=="+" || str=="-" || str=="*"|| str=="/"|| str=="(" || str=="" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_cheng+"*");
    }
}

void JSQ::on_btn_chu_clicked()  // /
{
    QString str_chu=ui->lineEdit->text();
    QString str=str_chu.mid(str_chu.length()-1,1);
    QString str_1=str_chu.mid(str_chu.length()-2,2);
    if(str=="+" || str=="-" || str=="*"|| str=="/"|| str=="(" || str=="" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_chu+"/");
    }
}

void JSQ::on_btn_tuige_clicked() //退格
{
    QString str_tuige=ui->lineEdit->text();
    str_tuige=str_tuige.mid(0,str_tuige.length()-1);
    ui->lineEdit->setText(str_tuige);
}

//void JSQ::on_btn_lg_clicked()  // lg
//{
//    QString str_lg=ui->lineEdit->text();
//    QString str=str_lg.mid(str_lg.length()-1,1);
//    if(str==")"){
//        ui->lineEdit->setText("ERROR");
//    }else{
//    ui->lineEdit->setText(str_lg+"lg(");
//    }
//}

//void JSQ::on_btn_daoshu_clicked()  //倒数
//{
//    QString str_daoshu=ui->lineEdit->text();
//    QString str=str_daoshu.mid(str_daoshu.length()-1,1);
//    QString str_1=str_daoshu.mid(str_daoshu.length()-2,2);
//    if(str=="" || str_1=="/0")
//    {
//       ui->lineEdit->setText("ERROR");
//    }else{
//    ui->lineEdit->setText(str_daoshu+"^(-1)");
//    }
//}

void JSQ::on_btn_jiecheng_clicked()  //阶乘
{
    QString str_jiecheng=ui->lineEdit->text();
    QString str=str_jiecheng.mid(str_jiecheng.length()-1,1);
    QString str_1=str_jiecheng.mid(str_jiecheng.length()-2,1);
    if(str=="" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_jiecheng+"^");
    }
}

void JSQ::on_btn_genghao_clicked()  // 根号
{
    QString str_genghao=ui->lineEdit->text();
    QString str=str_genghao.mid(str_genghao.length()-1,1);
    QString str_1=str_genghao.mid(str_genghao.length()-2,1);
    if(str=="" || str_1=="/0"){
        ui->lineEdit->setText("ERROR");
    }else{
    ui->lineEdit->setText(str_genghao+"^0.5");
    }
}

void JSQ::on_pushButton_clicked() // 关闭
{
   accept(); //关闭窗口
}

void JSQ::on_btn_d_clicked() //等于
{
      QString result=JSQ::calculate();
      ui->lineEdit->setText(result);
}


QString JSQ::calculate()  // 计算
{
    _tNode Node[NUM_OF_NUMBER];
    double num = 0;
    int   i = 0;                         //字符串的位置
    int num_of_point = 0;      //小数点后数字的个数
    int num_or_op = 0;         //浮点数和操作符个数
    int isfloat = 0;                 //小数点
    QString tmp = ui->lineEdit->text();
    int len = tmp.length(); //字符串长度
    QStack<double> last;  //构建一个数据栈
    last.push(num);
    while(i < len)
    {
        if(tmp[i] >= '0' && tmp[i] <= '9')
        {
            if(!isfloat)   //整数部分
            {
                num = num*10 + (tmp[i].toLatin1()-'0');   //tmp[i].toLatin1()将字符i转换为ASCII码
                ++i;
            }
            else   //小数部分
            {
                double per = 1;
                for(int k = 0;k < num_of_point;k++)
                    per *= 0.1;
                num +=  (tmp[i].toLatin1()-'0') * per;
                num_of_point++;
                ++i;
            }
        }
        else if(tmp[i] == '.')   //读到小数点
        {
            isfloat = 1;
            num_of_point = 1;
            ++i;
        }
        else  //读到操作符
        {
            last.push(num);
            if(num) //读到操作符后说明一个完整的数字输入完毕，要将数字、小数点等清零
            {
                Node[num_or_op].flag = KIND_NUMBER;
                Node[num_or_op].num.a = num;
                num = 0;
                ++num_or_op;
                isfloat= 0;
                num_of_point = 0;
            }
            Node[num_or_op].flag = KIND_OPERATOR;
            Node[num_or_op].num.op = tmp[i].toLatin1();
            ++num_or_op;
            ++i;
        }
    }
    if(num || num==0)   //最后一个操作数
    {
        Node[num_or_op].flag = KIND_NUMBER;
        Node[num_or_op].num.a = num;
        ++num_or_op;
        num = 0;
    }

    //将算数表达式改为后缀表达式
    QStack<_tNode>pNode;  //构建一个_tNode类型的栈pNode，是一个保存操作符栈
    _tNode _Node[NUM_OF_NUMBER];
    int j = 0;
    for(int m = 0 ; m< num_or_op ; )
    {
        if(Node[m].flag)  //符号入栈
        {
            if(pNode.isEmpty())
            {
                pNode.push(Node[m++]);

            }
            else
            {
                _tNode tem = pNode.top();
                int ret = process(tem.num.op,Node[m].num.op);
                switch(ret)
                {
                    case -1:
                        pNode.push(Node[m++]);
                        break;
                     case 1:
                          _Node[j++] = pNode.top();
                          pNode.pop();
                          break;
                       default:
                            pNode.pop();
                            m++;
                            break;
            }
            }
        }
    else
    {
        _Node[j++] = Node[m++];
    }
    }
while(!pNode.isEmpty()) //弹出栈中剩余的元素
{
    _tNode tem = pNode.top();
    if(tem.num.op != '(' &&tem.num.op != ')')
        _Node[j++] = tem;
     pNode.pop();
}

double d1,d2;
for(int n = 0;n < j;n++)
{
    if(_Node[n].flag) //遇到符号弹出数字进行计算
    {
        d2 = last.pop();
        //last.pop();
        d1 = last.pop();
//        last.pop();
        switch(_Node[n].num.op)
        {
            case '+':
                   d1 += d2;
                    break;
        case '-':
            d1 -= d2;
            break;
        case '*':
            d1 *= d2;
            break;
        case '/':
            d1 /= d2;
            break;
        case '^':
            d1=qPow(d1,d2);
        default:
            break;
        }
        last.push(d1);
    }
    else
    {
        last.push(_Node[n].num.a);
    }
}
tmp = QString::number(d1);
return tmp;
}
int JSQ::process(char a,char b) //比较优先级
{
//    char aim[7][8] = {{ ">><<<>>" },{ ">><<<>>" },{ ">>>><>>" },{ ">>>><>>" },{ "<<<<<=1" },{ ">>>>1>>" },{ "<<<<<1=" }};
    char aim[8][9] = {{">>>>><>>"},{"<>><<>>"},{"<>><<<>>"},{">>>>><>>"},{">>>>><>>"},{"<<<<<=1"},{">>>>>1>>"},{"<<<<<<1="}};
//    char sta[7] = {'+','-','*','/','(',')' };
    char sta[7] = {'^','+','-','*','/','(',')'};
    char result;
    int i,pa,pb;
    for (i = 0; i<7; i++)
          {
             if (a == sta[i])
             {
                 pa = i;
             }
             if (b == sta[i])
             {
                 pb = i;
             }
          }
    result = aim[pa][pb];

    if(result == '>')return 1;
    else if(result == '<')return -1;
    else return 0;
}

