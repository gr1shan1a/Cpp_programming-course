#ifndef TP_3_MAGAZINE_H
#define TP_3_MAGAZINE_H

#include "PrintedEdition.h"

class Magazine : public PrintedEdition {
public:
    Magazine() : PrintedEdition(), m_Nomer_pechati(1) {}
    Magazine(const string& name,
             int year,
             const string& publisher,
             int numPages,
             const string& annotation,
             int issueNumber);

    Magazine(const Magazine& other);
    void printToFile(ofstream& file) const override;
    void print() const override;

private:
    int m_Nomer_pechati;
};

#endif // TP_3_MAGAZINE_H
