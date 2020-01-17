from django.contrib import admin
from django.urls import path
from django.urls import include
from django.conf.urls import url
from django.conf import settings
from django.conf.urls.static import static

from .import views
urlpatterns = [
    path('channel/add', views.addChannel),
    path('channel/<str:channelId>', views.channelInfo),
    path('channel/del/<str:channelId>', views.delChannel),
    path('mqtt/add', views.addMqttBroker),
    # path('mqtt//<str:mqttName>',views.addMqttBroker),
    path('mqtt/del/<str:brokerName>', views.delMqttBroker),
    path('channel', views.channelsAndBrokers),
    path('', views.dashboard),
]
