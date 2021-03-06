# Generated by Django 2.2.1 on 2019-06-20 22:42

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='channelData',
            fields=[
                ('id', models.AutoField(auto_created=True,
                                        primary_key=True, serialize=False, verbose_name='ID')),
                ('timestamp', models.DateTimeField(auto_now_add=True)),
                ('data', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='mqttBroker',
            fields=[
                ('id', models.AutoField(auto_created=True,
                                        primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.TextField(default=None, max_length=100)),
                ('mqttAddr', models.TextField(default=None, max_length=200)),
                ('mqttPort', models.IntegerField(default=1883, null=True)),
                ('mqttUserName', models.TextField(default=None, null=True)),
                ('mqttPassword', models.TextField(default=None, null=True)),
                ('owner', models.ForeignKey(
                    null=True, on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='channel',
            fields=[
                ('id', models.AutoField(auto_created=True,
                                        primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.TextField(default='Label for channel', max_length=100)),
                ('key', models.TextField(
                    default='0x6abef14891fc4357', editable=False, unique=True)),
                ('mqttTopic', models.TextField(
                    default=None, max_length=200, null=True)),
                ('mqttBroker', models.ForeignKey(default=None, null=True,
                                                 on_delete=django.db.models.deletion.CASCADE, to='data.mqttBroker')),
                ('owner', models.ForeignKey(
                    null=True, on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]
