#ifndef ADDRESSABLEITEMCONTEXTMENU_H
#define ADDRESSABLEITEMCONTEXTMENU_H

#include "core/Iaito.h"
#include <QKeySequence>
#include <QMenu>

class MainWindow;

class IAITO_EXPORT AddressableItemContextMenu : public QMenu
{
    Q_OBJECT

public:
    AddressableItemContextMenu(QWidget *parent, MainWindow *mainWindow);
    ~AddressableItemContextMenu();

    /**
     * @brief Configure if addressable item refers to whole function or specific
     * address
     * @param wholeFunciton
     */
    void setWholeFunction(bool wholeFunciton);
public slots:
    void setOffset(RVA offset);
    void setTarget(RVA offset, QString name = QString());
    void clearTarget();
signals:
    void xrefsTriggered();

private:
    void onActionCopyAddress();
    void onActionShowXrefs();
    void onActionAddComment();

    virtual void aboutToShowSlot();

    QMenu *pluginMenu;
    QAction *pluginMenuAction;
    MainWindow *mainWindow;

    RVA offset;
    bool hasTarget = false;

protected:
    void setHasTarget(bool hasTarget);
    QAction *actionShowInMenu;
    QAction *actionCopyAddress;
    QAction *actionShowXrefs;
    QAction *actionAddcomment;

    QString name;
    bool wholeFunction = false;
};
#endif // ADDRESSABLEITEMCONTEXTMENU_H
