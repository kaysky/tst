#ifndef __CFORM__HPP__
#define __CFORM__HPP__


#include "ui_cli.h"



namespace kki {

///
/// \brief
///

class DlgForm
    : public QWidget
    , public Ui::client_form
{
    Q_OBJECT

public:
    DlgForm(QWidget* parent = NULL);
    virtual ~DlgForm() {}

Q_SIGNALS:


public Q_SLOTS:


};

}
#endif // __CFORM__HPP__


