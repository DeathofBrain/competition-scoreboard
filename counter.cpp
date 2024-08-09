#include "counter.h"
#include "ui_counter.h"
#include <QTimer>
#include <iostream>
#pragma execution_character_set("utf-8")
counter::counter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::counter)
{
    ui->setupUi(this);
    //ui->groupBox_3->setStyleSheet("QGroupBox {border: 0;}");
    //ui->rest_time_CN->setStyleSheet("QLabel { text-shadow: -1px -1px white, 1px -1px white, -1px 1px white, 1px 1px white; }");
    ui->rest_time_CN->setFrameShadow(QFrame::Raised);
    //初始化计时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &counter::timerSlot);
    timer->start(1000);
    //setStyleSheet("border-image:url(:/new/prefix1/img/back.jpg))");
    player_game->setMedia(QUrl("qrc:/new/prefix1/bgm/game_bgm.MP3"));
    player_game->setVolume(100);
    player_prepare->setMedia(QUrl("qrc:/new/prefix1/bgm/3min_prepare.MP3"));
    player_prepare->setVolume(100);
    player_tech_stop->setMedia(QUrl("qrc:/new/prefix1/bgm/pause.MP3"));
    player_tech_stop->setVolume(100);

}

counter::~counter()
{
    delete ui;
}
QString int2Time(int timeInSeconds) {
    int minutes = timeInSeconds / 60;
    int seconds = timeInSeconds % 60;

    // 使用 QString::number() 将整数转换为字符串，并确保格式为两位数
    QString timeString = QString("%1:%2")
                             .arg(minutes, 2, 10, QLatin1Char('0')) // 将分钟数转换为两位数的字符串
                             .arg(seconds, 2, 10, QLatin1Char('0')); // 将秒数转换为两位数的字符串

    return timeString;
}

void counter::timerSlot(){
    if (remainingTime > 0) {
        remainingTime--;
        ui->time->setText(int2Time(remainingTime));

        //std::cout<<int2Time(remainingTime).toStdString()<<std::endl;
    } else {
        if(tech_stop_flag)
        {
            ui->rest_time_CN->setText("三分钟准备时间");
            ui->rest_time_EN->setText("3 MIN PREPARING");
            tech_stop_flag = 0;
            prepare_flag = true;
            remainingTime = before_stop;
            player_tech_stop->stop();
            player_game->stop();
            player_prepare->play();
            ui->time->setText(int2Time(remainingTime));
        }
        else if (prepare_flag){
            prepare_flag = false;
            game_flag = true;
            ui->rest_time_CN->setText("比赛即将开始");
            ui->rest_time_EN->setText("MATCH WILL START...");
            remainingTime = 5;
            ui->time->setText(int2Time(remainingTime));
        }
        else if (game_flag){
            game_flag = false;
            on_time_all_clicked();
        }
        else if (finish_flag){
            finish_flag = false;
            ui->rest_time_CN->setText("比赛结束");
            ui->rest_time_EN->setText("MATCH FINISHED");
            remainingTime = 0;
            timer->stop();
            ui->time->setText(int2Time(remainingTime));
        }
        else
        {
            timer->stop();
        }

    }

}

void counter::update_score()
{
    ui->blue_1->display((blue_score/1)%10);
    ui->blue_2->display((blue_score/10)%10);
    ui->blue_3->display((blue_score/100)%10);
    ui->blue_4->display((blue_score/1000)%10);
    ui->red_1->display((red_score/1)%10);
    ui->red_2->display((red_score/10)%10);
    ui->red_3->display((red_score/100)%10);
    ui->red_4->display((red_score/1000)%10);
}

void counter::on_blue_butten_up_4_clicked()
{
    blue_score = blue_score + 1000;
    update_score();
}

void counter::on_blue_butten_up_3_clicked()
{
    blue_score = blue_score + 100;
    update_score();
}

void counter::on_blue_butten_up_2_clicked()
{
    blue_score = blue_score + 10;
    update_score();
}

void counter::on_blue_butten_up_1_clicked()
{
    blue_score = blue_score + 1;
    update_score();
}

void counter::on_blue_butten_down_4_clicked()
{
    if(blue_score >= 1000)
    {
        blue_score = blue_score - 1000;
        update_score();
    }
}

void counter::on_blue_butten_down_3_clicked()
{
    if(blue_score >= 100)
    {
        blue_score = blue_score - 100;
        update_score();
    }
}

void counter::on_blue_butten_down_2_clicked()
{
    if(blue_score >= 10)
    {
        blue_score = blue_score - 10;
        update_score();
    }
}

void counter::on_blue_butten_down_1_clicked()
{
    if(blue_score >= 1)
    {
        blue_score = blue_score - 1;
        update_score();
    }
}

void counter::on_red_butten_up_4_clicked()
{
    red_score = red_score + 1000;
    update_score();
}

void counter::on_red_butten_up_3_clicked()
{
    red_score = red_score + 100;
    update_score();
}

void counter::on_red_butten_up_2_clicked()
{
    red_score = red_score + 10;
    update_score();
}

void counter::on_red_butten_up_1_clicked()
{
    red_score = red_score + 1;
    update_score();
}

void counter::on_red_butten_down_4_clicked()
{
    if(red_score >= 1000)
    {
        red_score = red_score - 1000;
        update_score();
    }
}

void counter::on_red_butten_down_3_clicked()
{
    if(red_score >= 100)
    {
        red_score = red_score - 100;
        update_score();
    }
}

void counter::on_red_butten_down_2_clicked()
{
    if(red_score >= 10)
    {
        red_score = red_score - 10;
        update_score();
    }
}

void counter::on_red_butten_down_1_clicked()
{
    if(red_score >= 1)
    {
        red_score = red_score - 1;
        update_score();
    }
}


void counter::on_time_3min_clicked()
{
    tech_stop_flag = false;
    stop_all_music();
    player_prepare->play();
    ui->rest_time_CN->setText("三分钟准备时间");
    ui->rest_time_EN->setText("3 MIN PREPARING");
    prepare_flag = true;
    remainingTime = 180;
    ui->time->setText(int2Time(remainingTime));
    timer->start();
}


void counter::on_time_all_clicked()
{
    stop_all_music();
    player_game->play();
    finish_flag = true;
    ui->rest_time_CN->setText("比赛剩余时间");
    ui->rest_time_EN->setText("TIME REMAINING");
    remainingTime = 330 ;
    ui->time->setText(int2Time(remainingTime));
    timer->start();
}


void counter::on_time_tech_stop_clicked()
{
    player_prepare->pause();
    player_game->stop();
    //player_tech_stop->setLoopCount(-1);
    player_tech_stop->play();
    ui->rest_time_CN->setText("三分钟技术暂停");
    ui->rest_time_EN->setText("3 MIN TECH PAUSE");
    before_stop = remainingTime;
    tech_stop_flag = 1;
    remainingTime = 180;
    ui->time->setText(int2Time(remainingTime));
    timer->start();
}


void counter::on_blue_score_up_clicked()
{
    blue_score_all++;
    ui->blue_score_all->display(blue_score_all);
}


void counter::on_blue_score_down_clicked()
{
    if(blue_score_all >0)
    {
        blue_score_all--;
    }
    ui->blue_score_all->display(blue_score_all);
}


void counter::on_red_score_up_clicked()
{
    red_score_all++;
    ui->red_score_all->display(red_score_all);
}


void counter::on_red_score_down_clicked()
{
    if(red_score_all > 0)
    {
        red_score_all--;
    }
    ui->red_score_all->display(red_score_all);
}



void counter::on_all_screen_clicked()
{
    setWindowState(Qt::WindowFullScreen);
}


void counter::on_exit_clicked()
{
    exit(0);
}

void counter::stop_all_music()
{
    player_tech_stop->stop();
    player_game->stop();
    player_prepare->stop();
}

void counter::on_reset_clicked()
{
    stop_all_music();
    timer->stop();
    blue_score = 0;
    red_score = 0;
    blue_score_all = 0;
    red_score_all = 0;
    remainingTime = 0;
    before_stop = 0;
    tech_stop_flag = 0;
    game_flag = false;
    prepare_flag = false;
    five_seconds_flag = false;
    finish_flag = false;
    ui->rest_time_CN->setText("比赛结束");
    ui->rest_time_EN->setText("MATCH FINISHED");
    ui->time->setText(int2Time(remainingTime));
}

