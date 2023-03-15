#pragma once
#include <QNetworkAccessManager>

#include <QtWidgets/QWidget>
#include "ui_jsonhttpclient.h"

class JsonHttpClient : public QWidget
{
	Q_OBJECT

public:
	JsonHttpClient(QWidget* parent = nullptr);
	~JsonHttpClient();

private slots:
	void OnFetchButtonClicked();
	void DataReadyRead();
	void DataReadyFinished();

private:
	Ui::JsonHttpClientClass ui;
	QNetworkAccessManager* m_net_manager;
	QNetworkReply* m_net_reply;
	QByteArray* m_data_buffer;
};
