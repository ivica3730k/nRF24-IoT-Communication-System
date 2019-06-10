from django.urls import path
from django.urls import include
from django.conf.urls import url
from .import views
from django.views.generic.base import TemplateView

urlpatterns = [
    
    path('register',views.signup),
    path('', include('django.contrib.auth.urls')), 

    
]