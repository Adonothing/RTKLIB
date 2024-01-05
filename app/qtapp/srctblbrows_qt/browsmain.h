//---------------------------------------------------------------------------
#ifndef browsmainH
#define browsmainH
//---------------------------------------------------------------------------
#include <QMainWindow>
#include <QFutureWatcher>

#include "ui_browsmain.h"


class QShowEvent;
class QCloseEvent;
class StaListDialog;
class MapView;
class QTimer;

//---------------------------------------------------------------------------
class MainForm : public QMainWindow, private Ui::MainForm
{
    Q_OBJECT

protected:
    void showEvent(QShowEvent*);
    void closeEvent(QCloseEvent*);

public slots:
    void btnUpdateClicked();
    void btnListClicked();
    void addressChanged();
    void menuOpenClicked();
    void menuSaveClicked();
    void menuUpdateCasterClicked();
    void menuUpdateTableClicked();
    void menuViewStrClicked();
    void menuViewCasterClicked();
    void menuViewNetClicked();
    void menuViewSourceClicked();
    void menuAboutClicked();
    void btnMapClicked();
    void loadTimerExpired();
    void streamTableCellClicked(int ARow, int ACol);
    void casterTableCellDblClicked(int ARow, int ACol);
    void btnStatsionClicked();
    void updateCaster();
    void updateTable();
    void showMsg(const QString &);

private:
    QString addressList, addressCaster, sourceTable, iniFile;
    float fontScale;
    MapView *mapView;
    StaListDialog *staListDialog;
    QTimer *loadTimer;
    QFutureWatcher<char*> tableWatcher;
    QFutureWatcher<char*> casterWatcher;

    void getCaster(void);
    void getTable(void);
    void updateMap(void);
    void updateEnable(void);
    void showTable(void);
public:
    QStringList stationList;

    explicit MainForm(QWidget *parent = NULL);
};
//---------------------------------------------------------------------------
#endif
