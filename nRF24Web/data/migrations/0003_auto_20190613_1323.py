# Generated by Django 2.2.1 on 2019-06-13 13:23

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('data', '0002_auto_20190613_1248'),
    ]

    operations = [
        migrations.RenameField(
            model_name='channel',
            old_name='mqttLink',
            new_name='mqttTopic',
        ),
        migrations.AlterField(
            model_name='channel',
            name='fieldId',
            field=models.TextField(default='0x4541f25482fb4a97', editable=False, primary_key=True, serialize=False, unique=True),
        ),
    ]
