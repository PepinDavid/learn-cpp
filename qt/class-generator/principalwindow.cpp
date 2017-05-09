#include "principalwindow.h"
#include "windial.h"

PrincipalWindow::PrincipalWindow(QWidget *parent) : QWidget(parent)
{
    m_grid = new QGridLayout();

    m_name = new QLabel(tr("Nom de la classe : "));
    m_nameMother = new QLabel(tr("Nom de la classe mère : "));
    m_nameEdit = new QLineEdit();
    m_motherEdit = new QLineEdit();
    m_grid->addWidget(m_name, 0, 0, 1, 1);
    m_grid->addWidget(m_nameMother, 1, 0, 1, 1);
    m_grid->addWidget(m_nameEdit, 0, 1, 1, 3);
    m_grid->addWidget(m_motherEdit, 1, 1, 1, 3);

    m_option = new QLabel(tr("Options"));
    m_header = new QCheckBox(tr("Protéger le header contre les inclusions multiples"));
    m_construct = new QCheckBox(tr("Générer un constructeur par defaut"));
    m_destruct = new QCheckBox(tr("Générer un destructeur par defaut"));

    m_grid->addWidget(m_option, 3, 0, 1, 4);
    m_grid->addWidget(m_header, 4, 0);
    m_grid->addWidget(m_construct, 4, 1);
    m_grid->addWidget(m_destruct, 4, 2);

    m_addComment = new QGroupBox("Ajouter un commentaire");
    m_addComment->setCheckable(true);
    m_autor = new QLabel(tr("Auteur : "));
    m_autorEdit = new QLineEdit();
    m_date = new QLabel(tr("Date de création : "));
    m_dateEdit = new QDateEdit();
    m_comments = new QTextEdit();
    m_grid->addWidget(m_addComment, 5, 0);
    m_grid->addWidget(m_autor, 6, 0, 1, 1);
    m_grid->addWidget(m_autorEdit, 6, 1, 1, 3);
    m_grid->addWidget(m_date, 7, 0, 1, 1);
    m_grid->addWidget(m_dateEdit, 7, 1, 1, 3);
    m_grid->addWidget(m_comments, 8, 0, 4, 4);

    m_btnQuit = new QPushButton(tr("&Quit"));
    m_btnDial = new QPushButton(tr("&Generer"));
    m_grid->addWidget(m_btnQuit, 13, 2, 1, 1);
    m_grid->addWidget(m_btnDial, 13, 0, 1, 2);

    connect(m_btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_btnDial, SIGNAL(clicked()), this, SLOT(openDialog()));
    this->setLayout(m_grid);
}

void PrincipalWindow::openDialog(){
    if(m_name->text().isEmpty())
        QMessageBox::warning(this, "Error", "Veuillez entrer un nom pour la classe à générer");
    else{
        QString code = "coucou";
        code = "class "+m_nameEdit->text();
        if(!m_motherEdit->text().isEmpty())
            code += " : public " + m_motherEdit->text();

        code +="\n{\n\tpublic:\n\n";

        if(m_construct->isChecked())
            code +="\t\t"+m_nameEdit->text()+"();\n";
        if(m_destruct->isChecked())
            code +="\t\t~"+m_nameEdit->text()+"();\n";

        code += "\tprotected:\n\n";
        code += "\tprivate:\n\n";

        if(m_header->isChecked()){
            code = "#ifndef HEADER_"+
                m_nameEdit->text().toUpper() +
                    "\n#define HEADER_"+m_nameEdit->text().toUpper()+
                        "\n\n"+code;
            code += "}\n #endif";
        }

        if(m_addComment->isChecked()){
            code = "/*\n "+
                m_autor->text()+" "+m_autorEdit->text()+"\n"+
                    m_date->text()+" "+m_dateEdit->text()+"\n"+
                        "Rôle :\n"+
                            m_comments->toPlainText()+"\n"+
                                "*/\n\n"+code;
        }
        WinDial *dialog = new WinDial(code, this);
        dialog->exec();
    }

}
