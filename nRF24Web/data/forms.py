from django import forms

class addMqttBrokerForm(forms.Form):
    mqttAddr = forms.CharField(label='Address of mqtt broker', max_length=200)
    mqttPort = forms.IntegerField(label = 'Port for connecting to mqtt broker',required = False)
    mqttUserName = forms.CharField(label='Username for connection to broker', max_length=200,required=False)
    mqttPassword = forms.CharField(label='Password for connection to broker',max_length=200,required=False)
    name = forms.CharField(label='Description for mqtt broker',max_length=100,required=False)

class addChannelForm(forms.Form):
    name = forms.CharField(label='Description for channel', max_length=200, required=False)
    mqttTopic = forms.CharField(label='Mqtt topic for channel',max_length=200,required=False)
    mqttBroker = forms.CharField(label='Mqtt broker for channel',max_length=200,required=False)
