from django.shortcuts import render,redirect,loader
from django.contrib.auth import login, authenticate
from django.contrib import auth
from django.contrib.auth.models import User
from django.http import HttpResponse
import json

import myModule
from .models import *

def save(request):
    if request.method == "POST":
        data = json.loads(request.body)
        id = data['id']
        try:
            id = int(id)
            id = hex(id) #cast received uint64_t id intro string
            #id = str(id)
            print (id)
            dbdata = dataField.objects.get(fieldId = id) #get the object with the same id from database
            print("found in db")
            value = myModule.castString(data["data"],int(data["datatype"]))
            print(type(value))
        
        except:
            return HttpResponse("FAILED")

    template = loader.get_template('data.html')
    context = {}
    #return render(request, 'data.html')
    return HttpResponse(template.render(context,request))

def dashboard(request):
    current_user = request.user
    if current_user.id == None:
        return HttpResponse("You need to log in first to access your dashboard")

    if request.method == "GET":
        template = loader.get_template('dashboard.html')
        context = {
        }
        return HttpResponse(template.render(context,request))

def listChannels(request):
    current_user = request.user
    template = loader.get_template('channels.html')
    context = {}
    try:
        user = User.objects.get(id = current_user.id)
        listOfChannels = channel.objects.filter(owner = current_user)
        context["channels"] = listOfChannels
    except:
        pass
    
    return HttpResponse(template.render(context,request))    
