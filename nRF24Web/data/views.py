from django.shortcuts import render,redirect,loader
from django.contrib.auth import login, authenticate
from django.contrib import auth
from django.contrib.auth.models import User
from django.http import HttpResponse
import json

import myModule
from .models import *
from .forms import *

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

def channelsAndBrokers(request):
    current_user = request.user
    if current_user.id == None:
        return HttpResponse("You need to log in first to access your dashboard")
    template = loader.get_template('channels.html')
    context = {}
    user = User.objects.get(id = current_user.id)
    try:
        listOfChannels = channel.objects.filter(owner = current_user)
        context["channels"] = listOfChannels
    except:
        pass

    try:
        listOfBrokers = mqttBroker.objects.filter(owner = current_user)
        context["mqttBrokers"] = listOfBrokers
    except:
        pass
    
    return HttpResponse(template.render(context,request))    

def addMqttBroker(request):
    # if this is a POST request we need to process the form data
    if request.method == 'POST':
        # create a form instance and populate it with data from the request:
        form = addMqttBrokerForm(request.POST)
        # check whether it's valid:
        if form.is_valid() :
            current_user = request.user
            user = User.objects.get(id = current_user.id)
            owner = user
            addr = form.cleaned_data.get('mqttAddr')
            port = form.cleaned_data.get('mqttPort')
            name = form.cleaned_data.get('description')

            try:
                #this data is not mandatory
                userName = form.cleaned_data.get('mqttUserName')
                password = form.cleaned_data.get('mqttPassword')
            except:
                pass
            
            broker = mqttBroker()
            broker.owner = user
            broker.description = name
            broker.mqttAddr = addr
            broker.mqttPort = port
            try:
                broker.mqttUserName = userName
                broker.mqttPassword = password
            except:
                pass

            broker.save()
            print("broker saved")

        return redirect('/dashboard/channel')
        
