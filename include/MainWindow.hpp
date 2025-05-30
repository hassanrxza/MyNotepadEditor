#pragma once

// Qt
#include <QMainWindow> // Required for inheritance
#include <QString>
#include <QVector>
#include <QPair>
#include <QPushButton>
#include <QDockWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>
#include <QNetworkReply>
#include <QHBoxLayout>

class QVBoxLayout;
class QSyntaxStyle;
class QComboBox;
class QCheckBox;
class QSpinBox;
class QCompleter;
class QStyleSyntaxHighlighter;
class QCodeEditor;

/**
 * @brief Class, that describes demo main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Constructor.
     * @param parent Pointer to parent widget.
     */
    explicit MainWindow(QWidget* parent=nullptr);

private:

    void loadStyle(QString path);

    QString loadCode(QString path);

    void initData();

    void createWidgets();

    void setupWidgets();

    void performConnections();

    void sendRequestWithRetry(QNetworkRequest request, QByteArray data);

    QVBoxLayout* m_setupLayout;

    QComboBox* m_codeSampleCombobox;
    QComboBox* m_highlighterCombobox;
    QComboBox* m_completerCombobox;
    QComboBox* m_styleCombobox;
    QPushButton* openFileButton;
    QPushButton* saveFileButton;
    QString currentFilePath;

    QCheckBox* m_readOnlyCheckBox;
    QCheckBox* m_wordWrapCheckBox;
    QCheckBox* m_parenthesesEnabledCheckbox;
    QCheckBox* m_tabReplaceEnabledCheckbox;
    QSpinBox*  m_tabReplaceNumberSpinbox;
    QCheckBox* m_autoIndentationCheckbox;

    QCodeEditor* m_codeEditor;

    QVector<QPair<QString, QString>> m_codeSamples;
    QVector<QPair<QString, QCompleter*>> m_completers;
    QVector<QPair<QString, QStyleSyntaxHighlighter*>> m_highlighters;
    QVector<QPair<QString, QSyntaxStyle*>> m_styles;

    // ChatGPT integration
    QDockWidget* chatDockWidget;
    QWidget* chatWidget;
    QVBoxLayout* chatLayout;
    QTextEdit* chatDisplay;
    QLineEdit* chatInput;
    QPushButton* sendChatButton;
    QNetworkAccessManager* networkManager;
    QString openaiApiKey;
    QPushButton* toggleChatButton;
};

