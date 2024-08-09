#ifndef COUNTER_H
#define COUNTER_H

#include <QMainWindow>
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class counter; }
QT_END_NAMESPACE

class counter : public QMainWindow
{
    Q_OBJECT

public:
    counter(QWidget *parent = nullptr);
    ~counter();

private slots:
    void timerSlot();

    void on_blue_butten_up_4_clicked();

    void on_blue_butten_up_3_clicked();

    void on_blue_butten_up_2_clicked();

    void on_blue_butten_up_1_clicked();

    void on_blue_butten_down_4_clicked();

    void on_blue_butten_down_3_clicked();

    void on_blue_butten_down_2_clicked();

    void on_blue_butten_down_1_clicked();

    void on_red_butten_down_2_clicked();

    void on_red_butten_down_4_clicked();

    void on_red_butten_down_3_clicked();

    void on_red_butten_down_1_clicked();

    void on_red_butten_up_4_clicked();

    void on_red_butten_up_3_clicked();

    void on_red_butten_up_2_clicked();

    void on_red_butten_up_1_clicked();

    void on_time_3min_clicked();

    void on_time_all_clicked();

    void on_time_tech_stop_clicked();

    void on_blue_score_up_clicked();

    void on_blue_score_down_clicked();

    void on_red_score_up_clicked();

    void on_red_score_down_clicked();


    void on_all_screen_clicked();

    void on_exit_clicked();

    void stop_all_music();

    void on_reset_clicked();

private:
    Ui::counter *ui;
    int blue_score = 0;
    int red_score = 0;
    int blue_score_all = 0;
    int red_score_all = 0;
    int remainingTime = 0;
    int before_stop = 0;
    bool tech_stop_flag = 0;
    bool game_flag = false;
    bool prepare_flag = false;
    bool five_seconds_flag = false;
    bool finish_flag = false;
    void update_score();
    QTimer *timer;

    QMediaPlayer *player_prepare = new QMediaPlayer;
    QMediaPlayer *player_game = new QMediaPlayer;
    QMediaPlayer *player_tech_stop = new QMediaPlayer;
    qint64 pausePosition = 0;

};
#endif // COUNTER_H
