#include "jsonhttpclient.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

JsonHttpClient::JsonHttpClient(QWidget* parent)
	: QWidget(parent), m_net_manager(new QNetworkAccessManager(this)), m_net_reply(nullptr)
	  , m_data_buffer(new QByteArray)
{
    ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &JsonHttpClient::OnFetchButtonClicked);
    
}

JsonHttpClient::~JsonHttpClient()
{
	delete m_data_buffer;
}

void JsonHttpClient::OnFetchButtonClicked()
{
	const QUrl my_url("https://jsonplaceholder.typicode.com/posts");
	QNetworkRequest request;
	request.setUrl(my_url);

	m_net_reply = m_net_manager->get(request);
	connect(m_net_reply, &QIODevice::readyRead, this, &JsonHttpClient::DataReadyRead);
	connect(m_net_reply, &QNetworkReply::finished, this, &JsonHttpClient::DataReadyFinished);
}

void JsonHttpClient::DataReadyRead()
{
	m_data_buffer->append(m_net_reply->readAll());
}

void JsonHttpClient::DataReadyFinished()
{
    if (m_net_reply->error())
    {
        qDebug() << "Error : " << m_net_reply->errorString();
    }
    else
    {
        qDebug() << "Data fetch finished : " << QString(*m_data_buffer);

        //Turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*m_data_buffer);

        /*
        //What if you get an object from the server
        QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
        QJsonObject obObject = objectDoc.toVariant().toJsonObject();
        */

        //Turn document into json array
        QJsonArray array = doc.array();

        for (int i = 0; i < array.size(); i++)
        {
            QJsonObject object = array.at(i).toObject();
            QVariantMap map = object.toVariantMap();
            QString title = map["title"].toString();
            ui.listWidget->addItem("[" + QString::number(i + 1) + "]" +  title);

        }
    }
}
