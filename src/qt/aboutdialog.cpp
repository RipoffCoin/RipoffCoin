#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "clientmodel.h"
#include "clientversion.h"

// Copyright year (2009-this)
// Todo: update this when changing our copyright comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2014;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    // Set current copyright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; 2009-%1 ").arg(COPYRIGHT_YEAR) + tr("The Bitcoin developers | sorry guys ^^") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2011-2013 The Litecoin developers | sorry guys ^^")  + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2013-2014 The Guldencoin developers | sorry guys ^^") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2014-eternity The RipoffCoin \"developers\""));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
