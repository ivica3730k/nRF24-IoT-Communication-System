# Generated by Django 2.2.1 on 2019-06-20 22:48

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('data', '0002_auto_20190620_2246'),
    ]

    operations = [
        migrations.AlterField(
            model_name='channel',
            name='key',
            field=models.TextField(default=926, editable=False),
        ),
    ]
