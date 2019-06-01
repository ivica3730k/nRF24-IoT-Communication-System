from django.shortcuts import render,redirect
from django.http import HttpResponse
import json

def save(request):
    if request.method == "POST":
        data = json.loads(request.body)
        id = data['id']
        datatype = data['datatype']
        rawData = data['data']

        print(id)
        print(datatype)
        print(rawData)
    
              
    return HttpResponse("OK")