# Generated by Django 2.2.1 on 2019-06-13 12:48

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('data', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='mqttbroker',
            name='mqttPort',
            field=models.IntegerField(default=1883, null=True),
        ),
        migrations.AlterField(
            model_name='channel',
            name='fieldId',
            field=models.TextField(default='0x2318809b83b743e1', editable=False, primary_key=True, serialize=False, unique=True),
        ),
        migrations.AlterField(
            model_name='mqttbroker',
            name='mqttPassword',
            field=models.TextField(default=None, null=True),
        ),
        migrations.AlterField(
            model_name='mqttbroker',
            name='mqttUserName',
            field=models.TextField(default=None, null=True),
        ),
    ]
