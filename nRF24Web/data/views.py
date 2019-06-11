from django.shortcuts import render,redirect,loader
from django.contrib.auth import login, authenticate
from django.contrib import auth
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