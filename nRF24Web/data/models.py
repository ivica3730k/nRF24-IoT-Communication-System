from django.db import models
from django.contrib.auth.models import User
import uuid
# Create your models here.

class mqttBroker(models.Model):
    owner = models.ForeignKey(User,on_delete = models.CASCADE,null = True)
    description = models.TextField(default = None, max_length = 100)
    mqttAddr = models.TextField(primary_key=True,default=None, max_length=200)
    mqttPort = models.IntegerField(null=True,default = 1883)
    mqttUserName = models.TextField(default=None,null=True)
    mqttPassword = models.TextField(default=None,null=True)

class channel(models.Model):
    label = models.TextField(max_length=100,default="Label for channel")
    owner = models.ForeignKey(User,on_delete = models.CASCADE,null = True)
    fieldId = models.TextField(primary_key=True, default= hex(int(uuid.uuid4().hex[:16],16)), editable=False,unique = True)
    mqttLink = models.TextField(default=None, max_length=200,null=True)
    mqttBroker = models.ForeignKey(mqttBroker,on_delete = models.CASCADE,null = True,default = None)

class channelData(models.Model):
    field = models.ForeignKey(channel, on_delete=models.CASCADE)
    timestamp = models.DateTimeField(auto_now_add=True)
    data = models.TextField()
    