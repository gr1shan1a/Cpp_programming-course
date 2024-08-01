#include "PrintedEdition.h"

using namespace std;

PrintedEdition::PrintedEdition(const string& name,
                               int year,
                               const string& publisher,
                               int numPages,
                               const string& annotation)
       :m_name(name),
        m_year(year),
        m_publisher(publisher),
        m_numPages(numPages),
        m_annotation(annotation) {}


PrintedEdition::PrintedEdition(const PrintedEdition& other)
        : m_name(other.m_name),
        m_year(other.m_year),
        m_publisher(other.m_publisher),
        m_numPages(other.m_numPages),
        m_annotation(other.m_annotation) {}

PrintedEdition::~PrintedEdition() {}
