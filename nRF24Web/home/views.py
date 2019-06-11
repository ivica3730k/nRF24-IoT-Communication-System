from django.shortcuts import render,redirect,loader
from django.contrib.auth import login, authenticate
from django.contrib import auth
from django.http import HttpResponse
import json

from .models import *

# Create your views here.


def homepage(request):
    
    template = loader.get_template('index.html')
    context = {}
    #return render(request, 'data.html')
    return HttpResponse(template.render(context,request))