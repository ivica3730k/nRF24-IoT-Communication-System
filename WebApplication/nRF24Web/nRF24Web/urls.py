from django.contrib import admin
from django.urls import path
from django.urls import include

urlpatterns = [
    path('user/', include('usermanagment.urls')),
    path('dashboard/', include('data.urls')),
    path('', include('home.urls')),

]
