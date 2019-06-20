from django.db import models
from django.contrib.auth.models import User
import uuid
import random, string


class mqttBroker(models.Model):
    name = models.TextField(default = None, max_length = 100)
    owner = models.ForeignKey(User,on_delete = models.CASCADE,null = True)
    mqttAddr = models.TextField(default=None, max_length=200)
    mqttPort = models.IntegerField(null=True,default = 1883)
    mqttUserName = models.TextField(default=None,null=True)
    mqttPassword = models.TextField(default=None,null=True)

class channel(models.Model):
    name = models.TextField(max_length=100,default="Label for channel")
    owner = models.ForeignKey(User,on_delete = models.CASCADE,null = True)
    key =  models.TextField(default=None,editable=True,unique = True)
    mqttTopic = models.TextField(default=None, max_length=200,null=True)
    mqttBroker = models.ForeignKey(mqttBroker,on_delete = models.CASCADE,null = True,default = None)

class channelData(models.Model):
    timestamp = models.DateTimeField(auto_now_add=True)
    data = models.TextField()
    