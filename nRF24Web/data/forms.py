from django import forms

class addMqttBrokerForm(forms.Form):
    mqttAddr = forms.CharField(label='Address of mqtt broker', max_length=200)
    mqttPort = forms.IntegerField(label = 'Port for connecting to mqtt broker',required = False)
    mqttUserName = forms.CharField(label='Username for connection to broker', max_length=200,required=False)
    mqttPassword = forms.CharField(label='Password for connection to broker',max_length=200,required=False)
    description =  forms.CharField(label='Description for mqtt broker',max_length=100,required=False)