from django.contrib import admin
from django.urls import path
from django.urls import include
from django.conf.urls import url
from django.conf import settings
from django.conf.urls.static import static

from .import views
urlpatterns = [

    path('/channel',views.listChannels),
    path('',views.dashboard),
]
